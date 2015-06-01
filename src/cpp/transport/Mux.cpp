#include "Mux.h"
#include <common/Logger.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>

using namespace xiyao::common;

namespace xiyao {
    namespace transport {
        Mux::Mux(size_t max_events = 10)
            :mPoll(false), mMaxEvents(max_events) {
            mEvList = new epoll_event [mMaxEvents];

            mEpollFd = epoll_create(1000);
            if (mEpollFd < 0) {
                Logger::error(TAG, "Creating epoll fd");
                throw std::runtime_error("Creating epoll fd");
            }
        }

        Mux::~Mux() {
            stop();
            close(mEpollFd);

            delete [] mEvList;
        }

        bool Mux::start() {
            if (mPoll) {
                return false;
            }

            mPoll = true;
            mThd.reset(new std::thread(&Mux::poll, this));

            return true;
        }

        bool Mux::stop() {

            if (mEpollFd >= 0) {
                mPoll = false;
                mThd->join();

                close(mEpollFd);
                mEpollFd = -1;
            }

            return true;
        }

        bool Mux::add(int fd, const std::function<void(int)> &handle) {
            struct epoll_event ev;
            ev.events = EPOLLIN;
            ev.data.ptr = (void*)(&handle);
            if (epoll_ctl(mEpollFd, EPOLL_CTL_ADD, fd, &ev) < 0) {
                Logger::error(TAG, "Add fd");
                return false;
            }

            return true;
        }

        bool Mux::remove(int fd) {
            if (epoll_ctl(mEpollFd, EPOLL_CTL_DEL, fd, nullptr) < 0) {
                Logger::error(TAG, "Remove fd");
                return false;
            }

            return true;
        }

        void Mux::poll() {
            while (mPoll) {
                int rc = epoll_wait(mEpollFd, mEvList, mMaxEvents, 5000);
                if (rc == 0) { //timeout
                    continue;
                }
                else if(rc < 0) {
                    Logger::error(TAG, "epoll_wait");
                    break;;
                }
                else { //process the event
                    for (int i = 0; i < rc; ++i) {
                        (*(std::function<void(int)>*)(mEvList[i].data.ptr))(mEvList[i].events);
                    }
                }
            }
        }
    } //namespace transport
} //namespace xiyao

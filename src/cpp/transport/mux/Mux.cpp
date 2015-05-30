#include "Mux.h"
#include <common/logger/Logger.h>

using namespace xiyao::common;

namespace xiyao {
    namespace transport {
        bool Mux::start() {
            mEpollFd = epoll_create(1000);
            if (EpollFd < 0) {
                Logger::error(TAG, "Creating epoll fd");
                return false;
            }

            return true;
        }

        bool Mux::stop() {
            if (mEpollFd >= 0) {
                close(mEpollFd);
                mEpollFd = -1;
            }
        }

        bool Mux::add(int fd) {
            struct epoll_event ev;
            ev.events = EPOLLIN;
            ev.data.fd = fd;
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

        bool Mux::poll() {
            while (true) {
                int rc = epoll_wait(mEpollfd, mEventList, 10, 5000);
                if (rc == 0) { //timeout
                    continue;
                }
                else if(rc < 0) { error
                    Logger::error(TAG, "epoll_wait");
                    return false;
                }
                else { //process the event
                    for (int i = 0; i < rc; ++i) {
                        if (mEvList[i].events & EPOLLIN) {
                        }
                        else if(mEvList[i].events & (EPOLLHUP | EPOLLERR)) {
                            if (close(mEvList[i].data.fd) == -1) {
                                Logger::error(TAG, "close fd");
                            }
                        }
                    }
                }
            }
        }
    } //namespace transport
} //namespace xiyao

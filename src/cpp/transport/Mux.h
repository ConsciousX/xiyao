#pragma once

#include <sys/epoll.h>
#include <functional>
#include <thread>
#include <string>

namespace xiyao {
    namespace transport {
        class Mux {
        public:
            Mux(size_t max_num_of_events);
            virtual ~Mux();
            bool start();
            bool stop();

            bool add(int fd, const std::function<void(int)> &handle);
            bool remove(int fd);
        private:
            void poll();
            std::string TAG = "Mux";
            int mEpollFd = -1;
            bool mPoll = false;
            size_t mMaxEvents;
            struct epoll_event *mEvList;
            std::shared_ptr<std::thread> mThd;
        };
    } //namespace transport
} //namespace xiyao

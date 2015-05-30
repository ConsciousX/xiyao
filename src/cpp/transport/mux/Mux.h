#pragma once

#include <sys/epoll.h>

namespace xiyao {
    namespace common {
        class Mux {
        public:
            bool start();
            bool stop();

            void add(int fd, Event event);
            void remove(int fd);
        private:
            bool poll();
            static std::string TAG = "Mux";
            int mEpollFd = -1;
            struct epoll_event mEvList[10];
        };
    } //namespace common
} //namespace xiyao

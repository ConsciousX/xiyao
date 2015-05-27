#pragma once

namespace xiyao {
    namespace common {
        class Epoll {
        public:
            void start();
            void stop();

            void addFd(unsigned int fd, Event event);
            void rmFd(unsgned int fd);
        };
    } //namespace common
} //namespace xiyao

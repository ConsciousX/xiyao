#pragma once

#include <string>
#include <vector>

namespace xiyao {
    namespace common {
        class Server {
        public:
            virtual void start() = 0;
            virtual void stop() = 0;
            virtual ~Server() {}
        private:
            std::string mIp;
            int mPort;
            int mSock;
            std::vector<int> mClientSocks;
        };
    } //namespace common
} //namespace xiyao


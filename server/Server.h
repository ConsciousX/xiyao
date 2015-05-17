#pragma once

#include <string>
#include <vector>

namespace xiyao {
    namespace common {
        class Server {
        public:
            void start();
            void stop();
        private:
            std::string mIp;
            int mPort;
            int mSock;
            std::vector<int> mClientSocks;
        };
    } //namespace common
} //namespace xiyao


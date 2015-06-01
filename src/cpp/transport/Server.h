#pragma once

#include <string>
#include <vector>

namespace xiyao {
    namespace transport {
        class Server {
        public:
            virtual bool start() = 0;
            virtual bool stop() = 0;
            virtual ~Server() {}
        private:
            std::string mIp;
            int mPort;
            int mSock;
            std::vector<int> mClientSocks;
        };
    } //namespace transport
} //namespace xiyao


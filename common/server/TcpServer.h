#pragma once

#include <common/server/Server.h>

namespace xiyao {
    namespace common {
        class TcpServer : public Server {
        public:
            virtual void start() override;
            virtual void stop() override;

            void set_port(unsigned int port);
            void set_ip(const std::string& ip);
        private:
            std::string mIP;
            int mPort;
            int mSock;
            std::vector<int> mClientSocks;
        };
    } //namespace common
} //namespace xiyao

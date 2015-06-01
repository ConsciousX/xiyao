#pragma once

#include <transport/Server.h>
#include <transport/Mux.h>
#include <memory>
#include <transport/Acceptor.h>

namespace xiyao {
    namespace transport {
        class Socket;
        class TcpServer : public Server {
        public:
            virtual bool start() override;
            virtual bool stop() override;

            void set_port(unsigned int port);
            void set_ip(const std::string& ip);
        private:
            friend class Acceptor;
            void addSock(Socket* sock);
        private:
            std::string TAG = "TcpServer";
            std::string mIP;
            int mPort;
            int mSock;
            std::vector<Socket*> mClientSocks;
            std::shared_ptr<Acceptor> mAcceptor;
            Mux mMux;
        };
    } //namespace transport
} //namespace xiyao

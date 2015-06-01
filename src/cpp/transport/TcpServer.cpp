#include "TcpServer.h"
#include <transport/Socket.h>

#include <common/Logger.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace xiyao::common;

namespace xiyao {
    namespace transport {
        bool TcpServer::start() {
            mSock  = socket(AF_INET, SOCK_STREAM, 0);

            if (mSock < 0) {
                Logger::error(TAG, "Error opening sock");
                return false;
            }

            struct sockaddr_in serv_addr;
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_addr.s_addr = INADDR_ANY;
            serv_addr.sin_port = htons(mPort);

            //Bind
            if (bind(mSock, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
                Logger::error(TAG, "ERROR on binding");
                return false;
            }

            if (listen(mSock, 100) < 0) {
                Logger::error(TAG, "ERROR on listening");
                return false;
            }

            mAcceptor.reset(new Acceptor(this, &mMux, mSock));

            mMux.start();

            return true;
        }

        bool TcpServer::stop() {
            for (auto i : mClientSocks) {
                i->close();
            }

            close(mSock);

            return true;
        }

        void TcpServer::set_port(unsigned int port) {
            mPort = port;
        }

        void TcpServer::set_ip(const std::string& ip) {
            mIP = ip;
        }

        void TcpServer::addSock(Socket* sock) {
            mClientSocks.emplace_back(sock);
        }

    } //namespace transport
} //namespace xiyao

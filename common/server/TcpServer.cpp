#include "TcpServer.h"

#include <common/logger/Logger.h>

namespace xiyao {
    namespace commmon {
        void TcpServer::start() {
            mSock  = socket(AF_INET, SOCK_STREAM, 0);

            if (mSock < 0) {
                Logger::error("Error opening sock");
                return;
            }

            struct sockaddr_in server_addr, cli_addr;
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_addr.s_addr = INADDR_ANY;
            serv_addr.sin_port = htons(mPort);

            //Bind
            if (bind(mSock, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
                Logger::error("ERROR on binding");
            }

            listen(mSock, 5);

            while (true) {
                clilen = sizeof(cli_addr);
                int cli_sock = accept(msock, (struct sockaddr *)&cle_addr,
                        &clilen);
                if (cli_sock < 0) {
                    Logger::error("Error on accecting");
                    return;
                }

                mClientSocks.emplace_back(cli_sock);
            }

            void TcpServer::stop() {
                for (auto i : mClientSocks) {
                    close(i);
                }

                close(mSock);
            }

            void TcpServer::set_port(unsigned int port) {
                mPort = port;
            }

            void TcpServer::set_ip(const std::string& ip) {
                mIP = ip;
            }

        } //namespace common
    } //namespace xiyao

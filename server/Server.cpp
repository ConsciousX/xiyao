#include <server.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

namespace xiyao {
    namespace common {
        void Server::start() {
            mSock  = socket(AF_INET, SOCK_STREAM, 0);

            if (mSock < 0) {
                std::cerr<<"Error opening sock"<<std::endl;
                exit(1);
            }

            struct sockaddr_in server_addr, cli_addr;
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_addr.s_addr = INADDR_ANY;
            serv_addr.sin_port = htons(mPort);
            
            //Bind
            if (bind(mSock, (struct sockaddr *) &serv_addr,
                        sizeof(serv_addr)) < 0) {
                std::cerr<<"ERROR on binding"<<std::endl;
            }

            listen(mSock, 5);
            clilen = sizeof(cli_addr);
            int cli_sock = accept(msock, (struct sockaddr *)&cle_addr,
                    &clilen);
            if (cli_sock < 0) {
                std::cerr ("ERROR on accept");
        }


        void Server::stop() {
        }
    } //namespace common
} //namespace xiyao

#include "Client.h"

#include <stdexcept>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#include <string>
#include <iostream>

namespace xiyao {
    namespace common {
        Client::Client() {
            mSock = socket(AF_INET, SOCK_STREAM, 0);
            if (mSock < 0) {
                throw std::runtime_error("ERROR opening socket");
            }
        }

        void Client::connect(const char* ip, int port) {
            struct sockaddr_in addr;
            addr.sin_family = AF_INET;
            addr.sin_port = htons(port);
            inet_pton(AF_INET, ip, &addr.sin_addr);

            if (::connect(mSock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
                std::cerr<<"ERROR connecting"<<std::endl;
            }
            else {
                std::cout<<"Connect"<<std::endl;
            }
        }

        void Client::poll() {
            while (true) {
                std::cout<<"Please enter message"<<std::endl;
                char buffer[256];
                std::cin>>buffer;
                int n = write(mSock, buffer, strlen(buffer));
                if (n < 0) {
                    std::cerr<<"ERROR sending message"<<std::endl;
                }
                else {
                    std::cout<<"Send "<<n<<std::endl;
                }

                n = read(mSock, buffer, 255);
                if (n < 0) {
                    std::cerr<<"ERROR reading message"<<std::endl;
                }
                else {
                    std::cout<<"Receive "<<buffer<<std::endl;
                }
            }
        }
    } //namespace common
} //namespace xiyao



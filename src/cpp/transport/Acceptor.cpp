#include "Acceptor.h"

#include <transport/Mux.h>
#include <transport/TcpServer.h>

#include <sys/socket.h>
#include <sys/epoll.h>
#include <common/Logger.h>
#include <transport/Socket.h>

using namespace xiyao::common;

namespace xiyao {
    namespace transport {
        Acceptor::Acceptor(TcpServer *tcp_server, Mux *mux, int sock)
            :mServer(tcp_server), mMux(mux), mSock(sock)
        {
            mMux->add(mSock, std::bind(&Acceptor::onEvent, this, std::placeholders::_1));
        }

        void Acceptor::onEvent(int event) {
            while (true) {
                accept();
            };
        }

        void Acceptor::accept() {
            struct sockaddr addr;
            socklen_t len;
            int fd = ::accept(mSock, &addr, &len);
            if (fd < 0) {
                Logger::error(TAG, "accept");
                return;
            }
            else {
                Socket* sock = new Socket(mMux, fd);
                mServer->addSock(sock);
            }
        }
    } //namespace transport
} //xiyao

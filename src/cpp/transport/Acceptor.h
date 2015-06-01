#pragma once

#include <string>

namespace xiyao {
    namespace transport {
        class Mux;
        class TcpServer;
        class Acceptor {
            public:
                Acceptor(TcpServer* tcp_server, Mux *mux, int sock);
                void onEvent(int event);
                void accept();
            private:
                std::string TAG = "Acceptor";
                TcpServer *mServer;
                Mux* mMux;
                int mSock;
        };
    } //namespace transport
} //namespace xiyao

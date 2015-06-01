#pragma once

namespace xiyao {
    namespace transport {
        class Mux;
        class Socket {
        public:
            Socket(Mux *mux, int sock);
            void close();
        private:
            void onEvent(int event);
            int recv();
            int send();
        private:
            Mux *mMux;
            int mSock;
        };
    } //namespace tranport
} //namespace xiyao

#include "Socket.h"

#include <transport/Mux.h>
#include <fcntl.h>
#include <unistd.h>

namespace xiyao {
    namespace transport {
        Socket::Socket(Mux *mux, int sock)
            :mMux(mux), mSock(sock)
        {
            mMux->add(mSock, std::bind(&Socket::onEvent, this, std::placeholders::_1));
        }

        void Socket::onEvent(int event) {
        }

        void Socket::close() {
            ::close(mSock);
        }
    } //namespace tranport
} //namespace xiyao

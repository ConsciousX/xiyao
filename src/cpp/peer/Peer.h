#pragma once

#include <peer/PeerClient.h>

namespace xiyao {
    namespace peer {
        class Peer {
        public:
        private:
            std::string nId;
            PeerClient mPeerClient;
            TcpServer mServer;
            std::list<PeerEnd> mPeers;
        };
    } //namespace peer
} //namespace xiyao

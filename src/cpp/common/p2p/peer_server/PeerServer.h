#pragma

namespace xiyao {
    namespace p2p {
        class PeerServer {
        public:
            PeerServer();
            void start();
            void stop();
        private:
            std::map<std::string, Peer> mPeerMap;
        };
    } //namespace p2p
} //namespace xiyao

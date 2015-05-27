#pragma once

namespace xiyao {
    namespace p2p {
        class Peer {
        public:
        private:
            std::string mIp;
            unsigned int mPort;
            std::string mUsername;
            std::string mPwd;
        };
    } //namespace p2p
} //namespace xiyao

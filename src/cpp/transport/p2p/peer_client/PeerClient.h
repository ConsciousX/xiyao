#pragma once

namespace xiyao {
    namespace p2p {
        class PeerClient {
        public:
            PeerClient();
            void login();

            void set_username();
            const std::string& username();

            void set_pwd();
            const std::string& pwd();

        private:
            std::string mUsername;
            std::string mPwd;
        };
    } //namespace p2p
} //namespace xiyao

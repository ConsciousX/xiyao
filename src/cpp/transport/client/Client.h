namespace xiyao {
    namespace common {
        
        class Client {
        public:
            Client();
            void connect(const char* ip, int port);
            void poll();
        private:
            int mSock;
        };
    } //namespace common
} //namespace xiyao

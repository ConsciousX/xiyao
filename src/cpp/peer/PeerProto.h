#pragma once

namespace xiyao {
    namespace peer {
        class PeerProto : public Proto {
        public:
            typedef uint16 msg_len_t;

            virtual bool procMsg(const char *msg, size_t n) override;
        };
    } //namespace peer
} //namesapce xiyao

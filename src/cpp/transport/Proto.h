#pragma once

namespace xiyao {
    namespace transport {
        class Proto {
        public:
            virtual bool procMsg(const char *msg, size_t n) = 0;
        };
    } //namespace transport
} //namespace xiyao

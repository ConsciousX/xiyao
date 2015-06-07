#include "PeerProto.h"

using namespace xiyao::common;

namespace xiyao {
    namespace peer {
        bool PeerProto::procMsg(const char *buf, size_t n) {
            char* cur = buf;
            int buf_remain_len = n;

            while (buf_remain_len > 0) {
                if (mMsgRemain == 0) {
                    if (buf_remain_len >= sizeof(msg_len_t)) {
                        mMsgLen = *((msg_len_t*)char);
                        cur += sizeof(msg_len_t);
                        mMsgStart = cur;
                        buf_remain_len -= sizeof(msg_len_t);
                        if (buf_remain_len >= mMsgLen) {
                            mHandle->procMsg(mMsgStart, mMsgLen);
                            buf_remain_len -= msg_len;
                            cur += msg_len;
                        }
                        else { //Partial read
                            mMsgRemain = mMsgLen - buf_remain_len;
                            return true;
                        }
                    }
                    else {
                        Logger::error("Invalid msg length");
                        return false;
                    }
                }
                else {
                    if (buf_remain_len >= mMsgRemain) {
                        mHandle->procMsg(mMsgStart, mMsgLen);
                        buf_remain_len -= mMsgRemain;
                        cur += mMsgRemain;
                        mMsgRemain = 0;
                    }
                    else {
                        mMsgRemain -= buf_remain_len;
                        return true;
                    }
                }
            }
        }
    } //namespace peer
} //namespace xiyao



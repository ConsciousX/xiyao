#include "Logger.h"

#include <ctime>
#include <sys/time.h>

using namespace std;

namespace xiyao {
    namespace common {
        Logger::Logger() {
            time_t now = time(nullptr);
            tm tm_now = *localtime(&now);

            char file_name[256];
            strftime(file_name, sizeof(file_name), "%Y%m%d_%H%M%S.log", &tm_now);
            mFile = file_name;

            mOfs.open(file_name);
            if (!mOfs.is_open()) {
                throw runtime_error("ERROR opening log file");
            }
        }

        Logger::~Logger() {
            if (mOfs.is_open()) {
                mOfs.close();
            }
        }

        void Logger::info(const string& tag, const string& str) {
            Logger::instance().write(string("[INFO][") + tag + "] " + str);
        }

        void Logger::debug(const string& tag, const string& str) {
            Logger::instance().write(string("[DEBUG][") + tag + "] " + str);
            Logger::instance().flush();
        }

        void Logger::warn(const string& tag, const string& str) {
            Logger::instance().write(string("[WARN][") + tag + "] " + str);
            Logger::instance().flush();
        }

        void Logger::error(const string& tag, const string& str) {
            Logger::instance().write(string("[ERROR][") + tag + "] " + str);
            Logger::instance().flush();
        }

        void Logger::write(const string& text) {
            timeval now;
            gettimeofday(&now, nullptr);
            tm tm_now = *localtime(&now.tv_sec);
            char temp[256];
            strftime(temp, sizeof(temp), "%H:%M:%S.", &tm_now);
            mOfs<<temp<<now.tv_usec<<": "<<text<<endl;
        }

        void Logger::flush() {
            mOfs.flush();
        }
    } //namespace common
} //xiyao

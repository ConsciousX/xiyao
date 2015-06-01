#pragma once

#include <common/Singleton.h>

#include <fstream>
#include <string>


namespace xiyao {
    namespace common {
        class Logger : public Singleton<Logger> {
        public:
            Logger();
            virtual ~Logger();
            static void info(const std::string& tag, const std::string& text);
            static void debug(const std::string& tag, const std::string& text);
            static void warn(const std::string& tag, const std::string& text);
            static void error(const std::string& tag, const std::string& text);
        private:
            void write(const std::string& text);
            void flush();

            std::ofstream mOfs;
            std::string mFile;
        };
    } //namespace comon
} //namespace xiyao

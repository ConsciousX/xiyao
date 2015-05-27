#pragma once

namespace xiyao {
    namespace common {
        class Logger {
        public:
            Logger();
            ~Logger();
            static void info(const std::string& tag, const std::string& text);
            static void debug(const std::string& tag, const std::string& text);
            static void warn(const std::string& tag, const std::string& text);
            static void error(const std::string& tag, const std::string& text);
        private:
            std::ofstream mOut;
        };
    } //namespace comon
} //namespace xiyao

#pragma once

#include <exception>

namespace xiyao {
    namespace common {
        template<class T>
        class Singleton {
        public:
            static T& instance() {
                if (mT == nullptr) {
                    mT = new T;
                }
                
                return *mT;
            }

            static void destroy() {
                delete mT;
            }

            virtual ~Singleton() {
                mT = nullptr;
            }

        protected:
            explicet Singleton() throw() {
                if (mT != nullptr) {
                    throw std::runtime_error("Singleton error");
                }
            }

        private:
            Singleton(const Singleton&) = delete;
            Singleton& operator=(const Singleton&) = delete;
            static T* mT;
        };

        template<class T>
        T* Singleton<T>::mT = nullptr;
    } //namespace common
} //namespace xiyao




#ifndef ERRORS_H
#define ERRORS_H

#include <stdio.h>

namespace tpg {
    namespace debug_info {
        template<typename ...Args>
        void alert(const char* format, Args... args) {
            fputs("\033[s\033[33mAlert: ", stdout);
            printf(format, args...);
            fputs("\033[0m\033[u", stdout);
        }
        
        template<typename ...Args>
        void error(const char* format, Args... args) {
            fputs("\033[s\033[31mError: ", stdout);
            printf(format, args...);
            fputs("\033[0m\033[u", stdout);
        }

        template<typename ...Args>
        void critical_error(const char* format, Args... args) {
            fputs("\033[31m\033[2JCritical error: ", stdout);
            printf(format, args...);
            fputs("\033[0m", stdout);
        }
    }
}

#endif

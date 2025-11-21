#pragma once
#include <stdio.h>

#define COLOR_RESET   "\033[0m"
#define COLOR_DEBUG   "\033[32m"
#define COLOR_LOG     "\033[0m"
#define COLOR_WARNING "\033[33m"
#define COLOR_ERROR   "\033[31m"
#define COLOR_FATAL   "\033[1;31;40m"

namespace Log {
    enum log_severity {
        SEVER_DEBUG,
        SEVER_LOG,
        SEVER_WARNING,
        SEVER_ERROR,
        SEVER_FATAL,
    };
    
    inline void log(const char* message, log_severity sever) {
        switch (sever) {
            case SEVER_DEBUG: {
                printf("%s[DEBUG] %s%s\n", COLOR_DEBUG, message, COLOR_RESET);
                break;
            }

            case SEVER_LOG: {
                printf("%s[LOG] %s%s\n", COLOR_LOG, message, COLOR_RESET);
                break;
            }

            case SEVER_WARNING: {
                printf("%s[WARNING] %s%s\n", COLOR_WARNING, message, COLOR_RESET);
                break;
            }

            case SEVER_ERROR: {
                printf("%s[ERROR] %s%s\n", COLOR_ERROR, message, COLOR_RESET);
                break;
            }
            
            case SEVER_FATAL: {
                printf("%s[FATAL] %s%s\n", COLOR_FATAL, message, COLOR_RESET);
                break;
            }

            default: {
                printf("%s[UNKNOWN] %s%s\n", COLOR_LOG, message, COLOR_RESET);
                break;
            }
        }
    }
}

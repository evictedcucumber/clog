#include "clog.h"
#include <stdio.h>

void clog_log_msg(const char* msg, int level) {
    char* level_str;
#ifdef CLOG_ENABLE_COLOURS
    switch (level) {
    case 1:
        level_str = "\x1b[34mDEBU\x1b[0m";
        break;
    case 2:
        level_str = "\x1b[32mINFO\x1b[0m";
        break;
    case 3:
        level_str = "\x1b[33mWARN\x1b[0m";
        break;
    case 4:
        level_str = "\x1b[31mERRO\x1b[0m";
        break;
    case 5:
        level_str = "\x1b[91mCRIT\x1b[0m";
        break;
    }
#else
    switch (level) {
    case 1:
        level_str = "DEBU";
        break;
    case 2:
        level_str = "INFO";
        break;
    case 3:
        level_str = "WARN";
        break;
    case 4:
        level_str = "ERRO";
        break;
    case 5:
        level_str = "CRIT";
        break;
    }
#endif

#ifdef CLOG_ENABLE_COLOURS
    char ftimestamp[40] = "";
#else
    char ftimestamp[26] = "";
#endif

#ifdef CLOG_ENABLE_TIMESTAMPS
#include <time.h>
    struct timespec timespec;
    clock_gettime(CLOCK_REALTIME, &timespec);
    struct tm timeinfo;
    localtime_r(&timespec.tv_sec, &timeinfo);

    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", &timeinfo);

#ifdef CLOG_ENABLE_COLOURS
    snprintf(ftimestamp, sizeof(ftimestamp), "(\x1b[36m%s.%03ld\x1b[0m)",
             timestamp, timespec.tv_nsec / 1000000);
#else
    snprintf(ftimestamp, sizeof(ftimestamp), "(%s.%03ld)", timestamp,
             timespec.tv_nsec / 1000000);
#endif
#endif

    printf("[%s]%s %s\n", level_str, ftimestamp, msg);
}

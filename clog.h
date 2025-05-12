#ifndef CLOG_H
#define CLOG_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CLOG_ENABLE_DEBUG
#define clog_log_debug(msg) clog_log_msg(msg, 1);
#else
#define clog_log_debug(msg) (void)0
#endif
#define clog_log_info(msg) clog_log_msg(msg, 2);
#define clog_log_warn(msg) clog_log_msg(msg, 3);
#define clog_log_error(msg) clog_log_msg(msg, 4);
#define clog_log_critical(msg) clog_log_msg(msg, 5);

#ifndef CLOG_PREFIX_GUARD
#define CLOG_PREFIX_GUARD
#ifndef CLOG_ENABLE_PREFIX

#define log_msg clog_log_msg

#define log_debug clog_log_debug
#define log_info clog_log_info
#define log_warn clog_log_warn
#define log_error clog_log_error
#define log_critical clog_log_critical

void clog_log_msg(const char* msg, int level);

#ifdef __cplusplus
}
#endif
#endif
#endif

#ifdef CLOG_IMPLEMENTATION
#include <stdio.h>
#include <time.h>

void clog_log_msg(const char* msg, int level) {
#ifdef CLOG_ENABLE_COLOURS
    char level_str[14];
    switch (level) {
    case 1:
        snprintf(level_str, sizeof(level_str), "\x1b[34mDEBU\x1b[0m");
        break;
    case 2:
        snprintf(level_str, sizeof(level_str), "\x1b[32mINFO\x1b[0m");
        break;
    case 3:
        snprintf(level_str, sizeof(level_str), "\x1b[33mWARN\x1b[0m");
        break;
    case 4:
        snprintf(level_str, sizeof(level_str), "\x1b[31mERRO\x1b[0m");
        break;
    case 5:
        snprintf(level_str, sizeof(level_str), "\x1b[91mCRIT\x1b[0m");
        break;
    }
#else
    char level_str[5];
    switch (level) {
    case 1:
        snprintf(level_str, sizeof(level_str), "DEBU");
        break;
    case 2:
        snprintf(level_str, sizeof(level_str), "INFO");
        break;
    case 3:
        snprintf(level_str, sizeof(level_str), "WARN");
        break;
    case 4:
        snprintf(level_str, sizeof(level_str), "ERRO");
        break;
    case 5:
        snprintf(level_str, sizeof(level_str), "CRIT");
        break;
    }
#endif

#ifdef CLOG_ENABLE_COLOURS
    char ftimestamp[40] = "";
#else
    char ftimestamp[26] = "";
#endif

#ifdef CLOG_ENABLE_TIMESTAMPS
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

#endif
#endif

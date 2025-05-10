#include "clog.h"

#include <stdio.h>
#include <time.h>

char* level_to_string(int colours, ClogLogLevel level) {
    switch (level) {
    case Debug:
        return (colours) ? "\x1b[34mDEBU\x1b[0m" : "DEBU";
    case Info:
        return (colours) ? "\x1b[32mINFO\x1b[0m" : "INFO";
    case Warn:
        return (colours) ? "\x1b[33mWARN\x1b[0m" : "WARN";
    case Error:
        return (colours) ? "\x1b[31mERRO\x1b[0m" : "ERRO";
    case Critical:
        return (colours) ? "\x1b[91mCRIT\x1b[0m" : "CRIT";
    }
}

static ClogLogger logger = {0, 0, "%Y-%m-%d %H:%M:%S"};

ClogLogger* clog_get_logger(void) { return &logger; }

void clog_log_msg(const char* msg, ClogLogLevel level) {
    char* level_str = level_to_string(logger.enable_colours, level);

    if (logger.enable_timestamps) {
        time_t rawtime;
        struct tm* timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);

        char timestamp[100];
        strftime(timestamp, sizeof(timestamp), logger.timestamp_format,
                 timeinfo);

        printf("[%s](%s) %s\n", level_str, timestamp, msg);
    } else {
        printf("[%s] %s\n", level_str, msg);
    }
}

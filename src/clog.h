#ifndef CLOGGER_H
#define CLOGGER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int enable_colours;
    int enable_timestamps;
    char* timestamp_format;
} ClogLogger;

typedef enum { Debug, Info, Warn, Error, Critical } ClogLogLevel;

ClogLogger* clog_get_logger(void);

void clog_log_msg(const char* msg, ClogLogLevel level);

#ifdef CLOG_ENABLE_DEBUG
#define clog_log_debug(msg) clog_log_msg(msg, Debug);
#else
#define clog_log_debug(msg) (void)0
#endif
#define clog_log_info(msg) clog_log_msg(msg, Info);
#define clog_log_warn(msg) clog_log_msg(msg, Warn);
#define clog_log_error(msg) clog_log_msg(msg, Error);
#define clog_log_critical(msg) clog_log_msg(msg, Critical);

#ifdef __cplusplus
}
#endif

#ifndef CLOG_PREFIX_GUARD
#define CLOG_PREFIX_GUARD
#ifndef CLOG_ENABLE_PREFIX

#define Logger ClogLogger
#define LogLevel ClogLogLevel

#define get_logger clog_get_logger
#define log_msg clog_log_msg

#define log_debug clog_log_debug
#define log_info clog_log_info
#define log_warn clog_log_warn
#define log_error clog_log_error
#define log_critical clog_log_critical

#endif
#endif
#endif

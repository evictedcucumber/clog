#ifndef CLOG_H
#define CLOG_H

#ifdef __cplusplus
extern "C" {
#endif

void clog_log_msg(const char*, int level);

#ifdef CLOG_ENABLE_DEBUG
#define clog_log_debug(msg) clog_log_msg(msg, 1);
#else
#define clog_log_debug(msg) (void)0
#endif
#define clog_log_info(msg) clog_log_msg(msg, 2);
#define clog_log_warn(msg) clog_log_msg(msg, 3);
#define clog_log_error(msg) clog_log_msg(msg, 4);
#define clog_log_critical(msg) clog_log_msg(msg, 5);

#ifdef __cplusplus
}
#endif

#ifndef CLOG_PREFIX_GUARD
#define CLOG_PREFIX_GUARD
#ifndef CLOG_ENABLE_PREFIX

#define log_msg clog_log_msg

#define log_debug clog_log_debug
#define log_info clog_log_info
#define log_warn clog_log_warn
#define log_error clog_log_error
#define log_critical clog_log_critical

#endif
#endif
#endif

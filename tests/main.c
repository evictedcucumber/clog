#include "clog.h"

#include "module.h"

#include <stdio.h>

void log_all(void) {
    log_debug("Debug Message");
    log_info("Info Message");
    log_warn("Warn Message");
    log_error("Error Message");
    log_critical("Critical Message");

    printf("\n");
}

int main(void) {
    printf("\x1b[1;4mNo Colours\x1b[0m\n");
    log_all();
    some_function();

    printf("\x1b[1;4mColours\x1b[0m\n");
    get_logger()->enable_colours = 1;
    log_all();
    some_function();

    printf("\x1b[1;4mTimestamps\x1b[0m\n");
    get_logger()->enable_timestamps = 1;
    log_all();
    some_function();

    return 0;
}

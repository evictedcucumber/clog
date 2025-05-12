#include "clog.h"
#include <stdio.h>

int main(void) {
    log_debug("Debug Message");
    log_info("Info Message");
    log_warn("Warn Message");
    log_error("Error Message");
    log_critical("Critical Message");

    printf("\n");

    return 0;
}

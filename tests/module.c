#include "module.h"
#include "clog.h"

#include <stdio.h>

void some_function(void) {
    log_debug("Debug Message from Module.c");
    log_info("Info Message from Module.c");
    log_warn("Warn Message from Module.c");
    log_error("Error Message from Module.c");
    log_critical("Critical Message from Module.c");

    printf("\n");
}

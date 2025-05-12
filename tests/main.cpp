#include "clog.h"
#include <iostream>

int main(void) {
    log_debug("Debug Message");
    log_info("Info Message");
    log_warn("Warn Message");
    log_error("Error Message");
    log_critical("Critical Message");

    std::cout << std::endl;

    return 0;
}

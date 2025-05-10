#include "module.hpp"
#include "clog.h"
#include <iostream>

void some_function(void) {
    log_debug("Debug Message from Module.cpp");
    log_info("Info Message from Module.cpp");
    log_warn("Warn Message from Module.cpp");
    log_error("Error Message from Module.cpp");
    log_critical("Critical Message from Module.cpp");

    std::cout << std::endl;
}

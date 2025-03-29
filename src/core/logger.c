#include "logger.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

static const char* level_labels[6] = {
    "[FATAL]: ",
    "[ERROR]: ",
    "[WARN]: ",
    "[INFO]: ",
    "[DEBUG]: ",
    "[TRACE]: ",
};

b8 logger_initialize(void)
{
    // TODO: log file
    return TRUE;
}

void logger_shutdown(void)
{
    // TODO: cleanup
}

void log_output(log_level_t level, const char* message, ...)
{
}

void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line)
{
    log_output(LOG_LEVEL_FATAL, "Assertion Failure: %s, message: '%s', in file: %s, line: %d\n", expression, message, file, line);
}

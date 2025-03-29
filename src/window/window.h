#pragma once

#include <stdbool.h>
#include <stdint.h>

struct platform_data_t;

typedef struct window {
    struct platform_data_t* data;
} window_t;

bool window_initialize(window_t* window, uint32_t width, uint32_t height, const char* title);
void window_shutdown(window_t* window);

void window_poll_events(void);
bool window_should_close(window_t* window);

// varius methods that interact with the data in a platform specific way

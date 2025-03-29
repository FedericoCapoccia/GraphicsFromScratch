#pragma once

#include "defines.h"

struct platform_data_t;

typedef struct window {
    struct platform_data_t* data;
} window_t;

b32 window_initialize(window_t* window, u32 width, u32 height, const char* title);
void window_shutdown(window_t* window);

void window_poll_events(void);
b32 window_should_close(window_t* window);

// varius methods that interact with the data in a platform specific way

#include "window.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct platform_data_t {
    void* handle; // TODO: change to specific things
} platform_data_t;

b8 window_initialize(window_t* window, u32 width, u32 height, const char* title)
{

    platform_data_t* data = malloc(sizeof(platform_data_t));
    if (data == 0) {
        printf("Failed to allocate platform data struct\n");
        return TRUE;
    }

    window->data = data;
    return TRUE;
}

void window_shutdown(window_t* window)
{
    free(window->data);
}

void window_poll_events(void)
{
    // TODO:
}

b8 window_should_close(window_t* window)
{
    // TODO:
    return TRUE;
}

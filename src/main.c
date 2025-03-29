#include "renderer/renderer.h"

#include <stdio.h>

// TODO: maybe create custom allocator for the Engine
// TODO: Create logger
// TODO: Dynamic array

int main(void)
{
    if (volkInitialize() != VK_SUCCESS) {
        printf("Failed to initialize volk\n");
        return -1;
    }

    window_t window = { 0 };
    if (!window_initialize(&window, 800, 600, "Engine")) {
        printf("Failed to initialize window\n");
        return -2;
    }

    renderer_t renderer = { 0 };
    if (!renderer_initialize(&renderer, &window, true)) {
        printf("Failed to initialize renderer\n");
        return -3;
    }

    while (!window_should_close(&window)) {
        window_poll_events();
    }

    return 0;
}

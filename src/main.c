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

    window_t window;
    window_initialize(&window, 800, 600, "Engine");

    renderer_t renderer;
    renderer_initialize(&renderer, &window, true);

    while (!window_should_close(&window)) {
        window_poll_events();
    }

    return 0;
}

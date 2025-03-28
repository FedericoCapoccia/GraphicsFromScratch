#include "renderer/renderer.h"
#include <stdio.h>

// TODO: maybe create custom allocator for the Engine
// TODO: Create logger
// TODO: Dynamic array

void glfw_error_callback(int code, const char* description)
{
    printf("GLFW error[%d]: [%s]\n", code, description);
}

int main(void)
{
    if (volkInitialize() != VK_SUCCESS) {
        printf("Failed to initialize volk\n");
        return -1;
    }

    if (glfwInit() == 0) {
        printf("Failed to initialize GLFW\n");
        return -2;
    }

    glfwSetErrorCallback(glfw_error_callback);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Engine", 0, 0);

    if (window == 0) {
        printf("Failed to create GLFW window\n");
        return -3;
    }

    renderer_t renderer;
    renderer_initialize(&renderer, window, true);

    // while (!glfwWindowShouldClose(window)) {
    //     glfwPollEvents();
    // }

    return 0;
}

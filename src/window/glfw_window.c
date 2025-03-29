#include "window.h"

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct platform_data_t {
    GLFWwindow* handle;
} platform_data_t;

void glfw_error_callback(int code, const char* description)
{
    printf("GLFW error[%d]: [%s]\n", code, description);
}

bool window_initialize(window_t* window, uint32_t width, uint32_t height, const char* title)
{
    if (glfwInit() == 0) {
        printf("Failed to initialize GLFW\n");
        return false;
    }

    glfwSetErrorCallback(glfw_error_callback);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    platform_data_t* data = malloc(sizeof(platform_data_t));
    if (data == 0) {
        printf("Failed to allocate platform data struct\n");
        return false;
    }

    data->handle = glfwCreateWindow(width, height, title, 0, 0);

    if (data->handle == 0) {
        printf("Failed to create GLFW window\n");
        return false;
    }

    window->data = data;
    return true;
}

void window_shutdown(window_t* window)
{
    glfwDestroyWindow(window->data->handle);
    glfwTerminate();
    free(window->data);
}

void window_poll_events(void)
{
    glfwPollEvents();
}

bool window_should_close(window_t* window)
{
    return glfwWindowShouldClose(window->data->handle);
}

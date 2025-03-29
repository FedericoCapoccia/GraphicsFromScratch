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

b8 window_initialize(window_t* window, u32 width, u32 height, const char* title)
{
    if (glfwInit() == 0) {
        printf("Failed to initialize GLFW\n");
        return FALSE;
    }

    glfwSetErrorCallback(glfw_error_callback);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    platform_data_t* data = malloc(sizeof(platform_data_t));
    if (data == 0) {
        printf("Failed to allocate platform data struct\n");
        return FALSE;
    }

    data->handle = glfwCreateWindow(width, height, title, 0, 0);

    if (data->handle == 0) {
        printf("Failed to create GLFW window\n");
        return FALSE;
    }

    window->data = data;
    return TRUE;
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

b8 window_should_close(window_t* window)
{
    return glfwWindowShouldClose(window->data->handle);
}

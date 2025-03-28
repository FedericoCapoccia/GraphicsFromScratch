#include <GLFW/glfw3.h>
#include <stdio.h>
#include <volk.h>

int main()
{
    if (volkInitialize() != VK_SUCCESS) {
        printf("Failed to initialize volk\n");
        return -1;
    }

    if (glfwInit() == 0) {
        printf("Failed to initialize GLFW\n");
        return -2;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Engine", nullptr, nullptr);
    if (window == nullptr) {
        printf("Failed to create GLFW window\n");
        return -3;
    }

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    return 0;
}

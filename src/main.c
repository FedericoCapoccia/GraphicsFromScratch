#define VOLK_IMPLEMENTATION

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <volk.h>
#include <vulkan/vk_enum_string_helper.h>

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

    VkApplicationInfo app_info = {
        .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
        .pApplicationName = "Engine",
        .applicationVersion = VK_MAKE_VERSION(1, 0, 0),
        .pEngineName = "GraphicsFromScratch",
        .engineVersion = VK_MAKE_VERSION(1, 0, 0),
        .apiVersion = VK_API_VERSION_1_4
    };

    const char* layers[] = { "VK_LAYER_KHRONOS_validation" };

    VkInstanceCreateInfo create_info = {
        .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        .pApplicationInfo = &app_info,
        .enabledLayerCount = 1,
        .ppEnabledLayerNames = layers
    };

    VkInstance instance;
    VkResult res = vkCreateInstance(&create_info, nullptr, &instance);
    if (res != VK_SUCCESS) {
        printf("Failed to create VkInstance: {%s}\n", string_VkResult(res));
    }

    // while (!glfwWindowShouldClose(window)) {
    //     glfwPollEvents();
    // }

    return 0;
}

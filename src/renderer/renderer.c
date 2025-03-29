#include "renderer.h"
#include "../window/window.h"

#include <stdio.h>

bool renderer_initialize(renderer_t* renderer, window_t* window, bool validation)
{
    VkApplicationInfo app_info = {
        .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
        .pApplicationName = "Engine",
        .applicationVersion = VK_MAKE_VERSION(1, 0, 0),
        .pEngineName = "GraphicsFromScratch",
        .engineVersion = VK_MAKE_VERSION(1, 0, 0),
        .apiVersion = VK_API_VERSION_1_4
    };

    const char* layers[] = { "VK_LAYER_KHRONOS_validation" };

    // uint32_t glfw_extension_count = 0;
    // const char** glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count); // do not free because it is managed by glfw directly

    VkInstanceCreateInfo create_info = {
        .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        .pApplicationInfo = &app_info,
        .enabledLayerCount = 1,
        .ppEnabledLayerNames = layers,
        // .enabledExtensionCount = glfw_extension_count,
        // .ppEnabledExtensionNames = glfw_extensions
    };

    {
        VkResult res = vkCreateInstance(&create_info, 0, &renderer->instance);
        if (res != VK_SUCCESS) {
            printf("Failed to create VkInstance: {%s}\n", string_VkResult(res));
        }
    }

    return true;
}

void renderer_shutdown(renderer_t* renderer)
{
    vkDestroyInstance(renderer->instance, 0);
}

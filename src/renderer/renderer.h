#pragma once

#include <GLFW/glfw3.h>
#include <stdbool.h>
#include <volk.h>
#include <vulkan/vk_enum_string_helper.h>

typedef struct renderer {
    VkInstance instance;
} renderer_t;

bool renderer_initialize(renderer_t* renderer, GLFWwindow* window, bool validation);

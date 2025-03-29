#pragma once

#include "defines.h"
#include "window/window.h"

#include <GLFW/glfw3.h>
#include <volk.h>
#include <vulkan/vk_enum_string_helper.h>

typedef struct renderer {
    VkInstance instance;
} renderer_t;

b32 renderer_initialize(renderer_t* renderer, window_t* window, b32 validation);
void renderer_shutdown(renderer_t* renderer);

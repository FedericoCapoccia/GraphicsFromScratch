#pragma once

#include "GLSS/window.hpp"
#include <fmt/core.h>
#include <wayland-client.h>

namespace glss {

struct WindowPlatformData {
    uint32_t width;
    uint32_t height;

    struct wl_display* display {};
    struct wl_registry* registry {};
    struct wl_compositor* compositor {};
    struct wl_surface* surface = {};
    struct wl_buffer* buffer {};
    struct wl_shm* shm {};
    uint8_t* pixl {};

    ~WindowPlatformData();
};

} // namespace glss

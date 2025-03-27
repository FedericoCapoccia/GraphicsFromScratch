#pragma once

#include "GLSS/window.hpp"
#include <fmt/core.h>
#include <wayland-client.h>

namespace glss {

struct Window::WindowPlatformData {
    bool init();
    ~WindowPlatformData();

    wl_display* display {};
};

} // namespace glss

#pragma once

#include "GLSS/window.hpp"
#include <GLFW/glfw3.h>
#include <fmt/core.h>

namespace glss {

struct WindowPlatformData {
    ~WindowPlatformData();
};

} // namespace glss

#pragma once

#include "GLSS/window.hpp"
#include <SDL3/SDL.h>
#include <fmt/core.h>

namespace glss {

struct WindowPlatformData {
    ~WindowPlatformData();
};

} // namespace glss

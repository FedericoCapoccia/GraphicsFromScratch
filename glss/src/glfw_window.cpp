#include "glfw_platform.hpp"
#include <cassert>

namespace glss { // Window:: stuff

Window::~Window()
{
    if (m_Data != nullptr) {
        delete m_Data;
    }
};

bool Window::init(uint32_t width, uint32_t height, const char* title)
{
    assert(width > 0);
    assert(height > 0);
    m_Title = title;

    WindowPlatformData* _state = new WindowPlatformData {};
    fmt::println("Created Window Platform Data");

    m_Data = _state;
    return true;
}

void Window::resize() {}

WindowPlatformData::~WindowPlatformData()
{
    fmt::println("Destoryed Window Platform Data");
}

} // namespace glss

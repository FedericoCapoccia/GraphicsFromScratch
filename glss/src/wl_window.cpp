#include "wl_platform.hpp"
#include <cassert>

namespace glss { // Window:: stuff

Window::Window()
{
    m_Width = 0;
    m_Height = 0;
    m_Title = nullptr;
    m_PlatformData = new WindowPlatformData;
}

Window::~Window()
{
    if (m_PlatformData != nullptr) {
        delete m_PlatformData;
    }
};

bool Window::init(uint32_t width, uint32_t height, const char* title)
{
    assert(width > 0);
    assert(height > 0);

    this->m_Width = width;
    this->m_Height = height;
    this->m_Title = title;
    this->m_PlatformData->init();

    return true;
}

} // namespace glss

namespace glss { // WindowPlatformData:: stuff

bool Window::WindowPlatformData::init()
{
    this->display = wl_display_connect(nullptr);
    if (this->display == nullptr) {
        fmt::println("Failed to connect to wayland display");
        return false;
    }

    fmt::println("Created Window Platform Data");
    return true;
}

Window::WindowPlatformData::~WindowPlatformData()
{
    if (this->display != nullptr) {
        wl_display_disconnect(this->display);
        fmt::println("Destoryed Window Platform Data");
    }
}

} // namespace glss

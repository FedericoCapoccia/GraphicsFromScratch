#pragma once

#include <cstdint>

namespace glss {

struct WindowSpec {};

struct Window {
public:
    bool init(uint32_t width, uint32_t height, const char* title);
    Window();
    ~Window();

private:
    uint32_t m_Width;
    uint32_t m_Height;
    const char* m_Title;

    struct WindowPlatformData;
    WindowPlatformData* m_PlatformData;
};

} // namespace glss

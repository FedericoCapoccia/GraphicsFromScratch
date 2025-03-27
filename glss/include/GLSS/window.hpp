#pragma once

#include <cstdint>

namespace glss {

struct WindowPlatformData; // forward decl

struct WindowSpec {};

struct Window {
public:
    bool init(uint32_t width, uint32_t height, const char* title);
    void resize();
    Window() = default;
    ~Window();

private:
    const char* m_Title;
    WindowPlatformData* m_Data;
};

} // namespace glss

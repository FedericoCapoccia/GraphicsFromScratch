#include "wl_platform.hpp"

#include <cassert>
#include <cstring>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#pragma region RegistryHandler
// TODO: https://www.youtube.com/watch?v=iIVIu7YRdY0&t=2283s
static void reg_handle_global(void* data, struct wl_registry* reg, uint32_t name, const char* interface, uint32_t version)
{
    auto state = (glss::WindowPlatformData*)data;

    if (strcmp(interface, wl_compositor_interface.name) == 0) {
        state->compositor = (wl_compositor*)wl_registry_bind(reg, name, &wl_compositor_interface, 4);
    }
    fmt::println("interface: '{}', version: {}, name {}", interface, version, name);
}

static void reg_handle_global_remove(void* data, wl_registry* reg, uint32_t name)
{
    (void)data;
    (void)reg;
    (void)name;
}

static const struct wl_registry_listener reg_listener = {
    .global = reg_handle_global,
    .global_remove = reg_handle_global_remove
};

#pragma endregion RegistryHandler

static int32_t alc_shm(uint64_t sz)
{
    int8_t name[8];
    name[0] = '/';
    name[7] = 0;
    for (uint8_t i = 1; i < 6; i++) {
        name[i] = (rand() & 23) + 97;
    }

    int32_t fd = shm_open((const char*)name, O_RDWR | O_CREAT | O_EXCL, S_IWUSR | S_IRUSR | S_IWOTH | S_IROTH);
    shm_unlink((const char*)name);
    ftruncate(fd, sz);

    return fd;
}

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

    WindowPlatformData* _state = new WindowPlatformData {
        .width = width,
        .height = height
    };

    m_Title = title;
    _state->display = wl_display_connect(nullptr);

    if (_state->display == nullptr) {
        fmt::println("Failed to connect to wayland display");
        return false;
    }

    _state->registry = wl_display_get_registry(_state->display);
    wl_registry_add_listener(_state->registry, &reg_listener, _state);
    wl_display_roundtrip(_state->display);

    _state->surface = wl_compositor_create_surface(_state->compositor);

    fmt::println("Created Window Platform Data");

    m_Data = _state;
    return true;
}

void Window::resize()
{
    const size_t size = m_Data->width * m_Data->height * 4;
    int32_t fd = alc_shm(size); // W*H*sizeof(RGBA)

    m_Data->pixl = (uint8_t*)mmap(
        0,
        size,
        PROT_READ | PROT_WRITE,
        MAP_SHARED, fd, 0);

    struct wl_shm_pool* pool = wl_shm_create_pool(m_Data->shm, fd, size);
    m_Data->buffer = wl_shm_pool_create_buffer(pool, 0, m_Data->width, m_Data->height, m_Data->width * 4, WL_SHM_FORMAT_ARGB8888);
    wl_shm_pool_destroy(pool);
    close(fd);
}

} // namespace glss

namespace glss { // WindowPlatformData:: stuff

WindowPlatformData::~WindowPlatformData()
{
    if (buffer != nullptr) {
        wl_buffer_destroy(buffer);
    }

    if (surface != nullptr) {
        wl_surface_destroy(surface);
    }

    if (display != nullptr) {
        wl_display_disconnect(display);
    }

    fmt::println("Destoryed Window Platform Data");
}

} // namespace glss

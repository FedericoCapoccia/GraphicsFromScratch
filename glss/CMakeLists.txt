add_library(GLSS STATIC)

set(GLSS_SOURCES
    ""
)

target_include_directories(GLSS PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src )
target_include_directories(GLSS PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include )

find_package(VulkanHeaders CONFIG)
target_link_libraries(GLSS PRIVATE Shared Vulkan::Headers)

message(STATUS "GLSS_BACKEND = ${GLSS_BACKEND}")

if (GLSS_BACKEND STREQUAL "SDL")
    message(STATUS "Using SDL as backend for GLSS")

    find_package(SDL3 REQUIRED)
    target_link_libraries(GLSS PRIVATE SDL3::SDL3)
    list(APPEND GLSS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/sdl3_window.cpp")

elseif (GLSS_BACKEND STREQUAL "GLFW")
    message(STATUS "Using GLFW as backend for GLSS")

    find_package(glfw3 CONFIG REQUIRED)
    target_compile_definitions(GLSS PRIVATE GLFW_INCLUDE_NONE=1)

    target_link_libraries(GLSS PRIVATE glfw)
    list(APPEND GLSS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/glfw_window.cpp")

elseif (GLSS_BACKEND STREQUAL "NATIVE")
    if(UNIX AND NOT APPLE)
        list(APPEND GLSS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/wl_window.cpp")
        target_link_libraries(GLSS PRIVATE wayland-client)
    elseif(WIN32)
        list(APPEND GLSS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/win32_window.cpp")
        target_link_libraries(GLSS PRIVATE)
    else()
        message(FATAL_ERROR "NATIVE platform not supported")
    endif()
else()
    message(FATAL_ERROR "Invalid GLSS_BACKEND value. Must be SDL, GLFW, or NATIVE.")
endif()


target_sources(GLSS PRIVATE ${GLSS_SOURCES})

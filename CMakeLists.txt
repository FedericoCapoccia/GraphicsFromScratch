cmake_minimum_required(VERSION 3.28)

if(WIN32 AND MSVC)
    set(VCPKG_TARGET_TRIPLET x64-windows-static)
endif()

if(UNIX AND NOT APPLE)
    set(CMAKE_C_COMPILER clang CACHE STRING "C Compiler")
    set(CMAKE_CXX_COMPILER clang++ CACHE STRING "C++ Compiler")
endif()

project(GraphicsFromScratch LANGUAGES C)
set(CMAKE_C_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

set(EXE_NAME "engine")
add_executable(${EXE_NAME})

set(SOURCES "${CMAKE_SOURCE_DIR}/src/main.c")

# =====================================================================================================================
# Platform specific
# =====================================================================================================================

if (WIN32)
    target_compile_definitions(${EXE_NAME} PRIVATE _WIN32)

    if(MSVC)
        target_compile_options(${EXE_NAME} PRIVATE /arch:AVX2 /W4 /EHsc) # SIMD optimizations
        target_compile_definitions(${EXE_NAME} PRIVATE _CRT_SECURE_NO_WARNINGS)
        set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
        set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")
    endif()

    # Windows specific implementations
    list(APPEND SOURCES "")

elseif(UNIX AND NOT APPLE)
    target_compile_definitions(${EXE_NAME} PRIVATE __linux__)
    target_compile_options(${EXE_NAME} PRIVATE -Wall -Wextra -Wpedantic)

    # Linux specific implementations
    list(APPEND SOURCES "")
endif()

target_sources(${EXE_NAME} PRIVATE ${SOURCES})

# =====================================================================================================================
# Libs
# =====================================================================================================================

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
target_compile_definitions(${EXE_NAME} PRIVATE GLFW_INCLUDE_NONE=1)

find_package(VulkanHeaders CONFIG)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(${EXE_NAME} PRIVATE Vulkan::Headers glfw)



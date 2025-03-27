cmake_minimum_required(VERSION 3.28)

function(set_clang_compiler)
    set(CMAKE_C_COMPILER clang CACHE STRING "C Compiler")
    set(CMAKE_CXX_COMPILER clang++ CACHE STRING "C++ Compiler")
    execute_process(COMMAND ${CMAKE_CXX_COMPILER} --version OUTPUT_VARIABLE CLANG_VERSION ERROR_QUIET)
    message(STATUS "Found Clang: ${CMAKE_CXX_COMPILER} ${CLANG_VERSION}")
    if(NOT CLANG_VERSION MATCHES "clang")
        message(FATAL_ERROR "Clang is required but not found. Please install Clang and try again.")
    endif()
endfunction()

if(WIN32 AND MSVC)
    set(VCPKG_TARGET_TRIPLET x64-windows-static)
endif()

project(GraphicsFromScratch)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_CXX_SCAN_FOR_MODULES 0) # prevents error on clang-scan-deps not found (disables module support)

if (WIN32)
    add_compile_definitions(-D_WIN32)

    if(MSVC)
        add_compile_options(/arch:AVX2 /W4 /EHsc) # SIMD optimizations
        add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
        set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
        set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")
    endif()

elseif(UNIX AND NOT APPLE)
    set_clang_compiler()
    add_compile_definitions(-D__linux__)
    add_compile_options(-Wall -Wextra -Wpedantic -fno-exceptions)
endif()

add_subdirectory(sandbox)
add_subdirectory(shared)
add_subdirectory(glss)
add_subdirectory(renderer)

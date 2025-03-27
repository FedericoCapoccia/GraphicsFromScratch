add_library(GLSS STATIC)

set(GLSS_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/window.cpp"
)

target_include_directories(GLSS PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src )
target_include_directories(GLSS PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include )

find_package(VulkanHeaders CONFIG)
target_link_libraries(GLSS PRIVATE Shared Vulkan::Headers)

if(UNIX AND NOT APPLE)
    list(APPEND GLSS_SOURCES "")
    target_link_libraries(GLSS PRIVATE wayland-client)
elseif(WIN32)
    list(APPEND GLSS_SOURCES "")
    target_link_libraries(GLSS PRIVATE)
endif()

target_sources(GLSS PRIVATE ${GLSS_SOURCES})


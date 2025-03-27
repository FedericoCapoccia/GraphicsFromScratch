add_library(Renderer STATIC)

set(Renderer_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/renderer.cpp"
)

target_include_directories(Renderer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src )
target_include_directories(Renderer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include )

find_package(VulkanHeaders CONFIG)
target_link_libraries(Renderer PRIVATE Shared GLSS Vulkan::Headers)

target_sources(Renderer PRIVATE ${Renderer_SOURCES})


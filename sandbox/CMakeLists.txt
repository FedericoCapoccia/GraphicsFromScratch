add_executable(Sandbox)

target_sources(Sandbox PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/application.cpp)

target_include_directories(Sandbox PRIVATE src)

target_link_libraries(Sandbox PRIVATE Shared GLSS Renderer)

add_library(Shared STATIC)

set(Shared_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/logger.cpp"
)

target_include_directories(Shared PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src )
target_include_directories(Shared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include )

find_package(fmt CONFIG REQUIRED)
target_link_libraries(Shared PUBLIC fmt::fmt)

if(UNIX AND NOT APPLE)
    list(APPEND Shared_SOURCES "")
    target_link_libraries(Shared PRIVATE)
elseif(WIN32)
    list(APPEND Shared_SOURCES "")
    target_link_libraries(Shared PRIVATE)
endif()

target_sources(Shared PRIVATE ${Shared_SOURCES})


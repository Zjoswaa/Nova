cmake_minimum_required(VERSION 3.31)
project(Nova)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE PROJECT_HEADERS include/*.hpp include/*.h)
file(GLOB_RECURSE PROJECT_SOURCES src/*.cpp src/*.cxx src/*.cc src/*.c)
file(GLOB VENDORS_SOURCES
        ${CMAKE_SOURCE_DIR}/vendor/glad/src/glad.c
        ${CMAKE_SOURCE_DIR}/vendor/imgui/*.cpp
        ${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_sdl2.cpp
        ${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_opengl3.cpp
)
file(GLOB PROJECT_CONFIGS CMakeLists.txt)

add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES} ${VENDORS_SOURCES} ${PROJECT_HEADERS})

target_link_libraries(${PROJECT_NAME} PUBLIC SDL2::SDL2 spdlog::spdlog ${GLAD_LIBRARIES})

target_include_directories(
        ${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/
        ${CMAKE_SOURCE_DIR}/vendor/glad/include/
        ${CMAKE_SOURCE_DIR}/vendor/SDL/include/
        ${CMAKE_SOURCE_DIR}/vendor/glm/glm/
        ${CMAKE_SOURCE_DIR}/vendor/imgui/
        ${CMAKE_SOURCE_DIR}/vendor/imgui/backends/
        ${CMAKE_SOURCE_DIR}/vendor/stb/
        ${CMAKE_SOURCE_DIR}/vendor/spdlog/include/
)

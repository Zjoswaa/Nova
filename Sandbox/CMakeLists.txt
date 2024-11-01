cmake_minimum_required(VERSION 3.31)
project(Sandbox)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE PROJECT_HEADERS src/*.hpp src/*.h)
file(GLOB_RECURSE PROJECT_SOURCES src/*.cpp src/*.cxx src/*.cc src/*.c)
file(GLOB PROJECT_CONFIGS CMakeLists.txt)

add_executable(${PROJECT_NAME} ${PROJECT_HEADERS} ${PROJECT_SOURCES} ${PROJECT_CONFIGS} ${CMAKE_SOURCE_DIR}/resources.rc)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/Nova/include/)

target_link_libraries(${PROJECT_NAME} PRIVATE Nova)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

# Copy resource files to binary directory
add_custom_target(copy-resources ALL
        COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_BINARY_DIR}/res
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/res
        ${PROJECT_BINARY_DIR}/res
        COMMENT "Copying ${CMAKE_SOURCE_DIR}/res to ${PROJECT_BINARY_DIR}/res"
)
add_dependencies(${PROJECT_NAME} copy-resources)

# Copy SDL2 library to binary directory
if(WIN32)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_BINARY_DIR}/vendor/SDL/SDL2d.dll
                ${PROJECT_BINARY_DIR}
                COMMENT "Copying SDL library to output directory"
        )
    elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_BINARY_DIR}/vendor/SDL/SDL2.dll
                ${PROJECT_BINARY_DIR}
                COMMENT "Copying SDL library to output directory"
        )
    endif()
elseif(UNIX AND NOT APPLE) # Linux
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_BINARY_DIR}/vendor/SDL/libSDL2d.so
                ${PROJECT_BINARY_DIR}
                COMMENT "Copying SDL library to output directory"
        )
    elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_BINARY_DIR}/vendor/SDL/libSDL2.so
                ${PROJECT_BINARY_DIR}
                COMMENT "Copying SDL library to output directory"
        )
    endif()
endif()

# Try to run without console in release mode
#if(CMAKE_BUILD_TYPE STREQUAL "Release")
#    if (WIN32) # Windows
#        if (MSVC)
#            target_link_options(${PROJECT_NAME} PRIVATE "/subsystem:windows /entry:mainCRTStartup")
#        elseif(MINGW)
#            target_link_options(${PROJECT_NAME} PRIVATE "-mwindows")
#        endif()
#    elseif (UNIX AND NOT APPLE) # Linux
#        if (MINGW)
#            target_link_options(${PROJECT_NAME} PRIVATE "-mwindows")
#        endif ()
#    endif()
#endif()

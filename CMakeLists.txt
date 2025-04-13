cmake_minimum_required(VERSION 3.31.1)
project(tetris-cpp VERSION 0.1.0 LANGUAGES C CXX)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows")

find_package(raylib CONFIG REQUIRED)
add_executable(tetris-cpp src/main.cpp src/grid.cpp src/colors.cpp src/position.cpp src/blocks.cpp src/block.cpp src/game.cpp)

# Copy asset Sounds / Font to the build 
set(SOUNDS_DIR ${CMAKE_SOURCE_DIR}/Sounds)
set(SOUNDS_DEST_DIR ${CMAKE_BINARY_DIR}/Sounds)

set(FONTS_DIR ${CMAKE_SOURCE_DIR}/Font)
set(FONTS_DEST_DIR ${CMAKE_BINARY_DIR}/Font)

add_custom_command(TARGET tetris-cpp POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${SOUNDS_DIR} ${SOUNDS_DEST_DIR})
add_custom_command(TARGET tetris-cpp POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${FONTS_DIR} ${FONTS_DEST_DIR})


target_link_libraries(tetris-cpp PRIVATE raylib)



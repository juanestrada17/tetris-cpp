cmake_minimum_required(VERSION 3.31.1)
project(tetris-cpp VERSION 0.1.0 LANGUAGES C CXX)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows")

find_package(raylib CONFIG REQUIRED)
add_executable(tetris-cpp main.cpp)


target_link_libraries(tetris-cpp PRIVATE raylib)



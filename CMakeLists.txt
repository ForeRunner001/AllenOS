cmake_minimum_required(VERSION 3.0)

project(AllenOS)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wno-sign-compare -Wno-unused-variable")

file(GLOB SRC_LIST "src/*.cpp" "src/*.cc")


add_library(allen_os SHARED ${SRC_LIST})

add_subdirectory(${PROJECT_SOURCE_DIR}/lib/libstd)
add_executable(AllenOS ${SRC_LIST})

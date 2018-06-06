cmake_minimum_required(VERSION 3.0)

project(AllenOS)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wno-sign-compare -Wno-unused-variable")

# Add source file in project root directory
aux_source_directory(./src SRC_FILE_LIST)

# Add header file include directories
include_directories(
        lib/
)

# Add block directories
add_subdirectory(lib)

#add_subdirectory(${PROJECT_SOURCE_DIR}/lib/libstd)
add_executable(AllenOS ${SRC_FILE_LIST})
target_link_libraries(
        AllenOS
        allenos_libstd
)

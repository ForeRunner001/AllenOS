# libstd
file(GLOB LIBSTD_SRC_LIST "src/*.cpp")
file(GLOB LIBSTD_INC_LIST "include/*.hpp")

# message(STATUS "${LIBSTD_INC_LIST}")
# foreach(f ${LIBSTD_INC_LIST})
    # message(STATUS "${f}")
# endforeach()

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
add_library(libstd SHARED EXCLUDE_FROM_ALL ${LIBSTD_INC_LIST})
set_target_properties(libstd PROPERTIES LINKER_LANGUAGE CXX)

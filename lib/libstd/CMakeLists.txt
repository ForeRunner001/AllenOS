
#file(GLOB LIBSTD_SRC_LIST "*.cpp" "*.cc")
#file(GLOB LIBSTD_INC_LIST "*.hpp" "*.h")
#
#message(STATUS ${LIBSTD_INC_LIST})
add_library(libstd SHARED EXCLUDE_FROM_ALL Singleton.hpp Types.hpp Vector.hpp Macros.hpp)
#target_include_directories()
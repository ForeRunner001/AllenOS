aux_source_directory(. LIBSTD_FILE_LIST)
add_library(allenos_libstd SHARED ${LIBSTD_FILE_LIST})
SET_TARGET_PROPERTIES(allenos_libstd PROPERTIES LINKER_LANGUAGE CXX)

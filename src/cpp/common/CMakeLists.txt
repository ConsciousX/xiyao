SET(LIB_NAME "common")

install_library(${LIB_NAME} SHARED)
target_link_libraries(${LIB_NAME})

install_header(${LIB_NAME})
set_install_paths(${LIB_NAME})


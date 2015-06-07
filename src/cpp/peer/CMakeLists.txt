set(APP_NAME "peer_server")

install_executable(${APP_NAME} main.cpp)
target_link_libraries(${APP_NAME} common transport)

set_install_paths(${APP_NAME})

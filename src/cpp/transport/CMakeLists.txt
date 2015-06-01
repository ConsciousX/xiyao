SET(LIB_NAME "transport")

install_library(${LIB_NAME} SHARED 
    Acceptor.cpp
    Mux.cpp
    Socket.cpp
    TcpServer.cpp)
target_link_libraries(${LIB_NAME} common)

install_header(${LIB_NAME})
set_install_paths(${LIB_NAME})


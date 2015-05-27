CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
project(xiyao)

SET(CMAKE_CXX_FLAGS "-std=c++11 -Wall -m64 -march=native -pthread -fPIC -fdiagnostics-color=always")
SET(CMAKE_CXX_FLAGS_DEBUG "-ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "-O3 -flto")

SET(CMAKE_C_FLAGS "-std=c++11 -Wall m64 -march=native -pthread -fPIC -fdiagnostics-color=always")
SET(CMAKE_C_FLAGS_DEBUG "-ggdb")
SET(CMAKE_C_FLAGS_RELEASE "-O3 -flto")

SET(CMAKE_EXE_LINKER_FLAGS "-z defs -rdynamic")
SET(CMAKE_MODULE_LINKER_FLAGS "-z defs -rdynamic")
SET(CMAKE_SHARED_LINKER_FLAGS "-z defs -rdynamic")

INCLUDE_DIRECTORIES(SYSTEM ${CMAKE_SOURCE_DIR}/src/cpp)

EXECUTE_PROCESS(
    COMMAND find src/cpp -name CMakeLists -exec dirname "{}" ";"
    COMMAND xargs
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} OUTPUT_VARIABLE SUBDIRS OUTPUT_STRIP_TRAILING_WHITESPACE)

SEPARATE_ARGUMENTS(SUBDIRS)
FOREACH(DIR ${SUBDIRS})
    MESSAGE("Adding ${DIR} for building")
    ADD_SUBDIRECTORY(${DIR})
ENDFOREACH()

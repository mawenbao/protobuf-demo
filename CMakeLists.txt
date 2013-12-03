cmake_minimum_required(VERSION 2.6)
project(protobuf-demo)

# compile proto files
set(PROTO_IN  news.proto)
set(PROTO_SRC news.pb.cc)
set(PROTO_OUT news.pb.h news.pb.cc test/)

add_custom_command(
    OUTPUT ${PROTO_OUT}
    COMMAND protoc --cpp_out . --java_out . ${PROTO_IN}
    DEPENDS ${PROTO_IN}
)
add_custom_target(proto DEPENDS ${PROTO_OUT})

aux_source_directory(. SRC_LIST)
list(APPEND SRC_LIST
    ${PROTO_SRC}
)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_VERBOSE_MAKEFILE on)

add_executable(demo ${SRC_LIST})
add_dependencies(demo proto)
target_link_libraries(demo protobuf)


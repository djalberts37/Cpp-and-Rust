include(FindProtobuf)
find_package(Protobuf REQUIRED)

protobuf_generate_cpp(PROTO_SRC PROTO_HEADER helloworld.proto)
add_library(proto ${PROTO_HEADER} ${PROTO_SRC})
target_include_directories(proto PUBLIC ${Protobuf_INCLUDE_DIRS})
include(FindProtobuf)
find_package(Protobuf REQUIRED)

add_library(proto OBJECT ${CMAKE_CURRENT_SOURCE_DIR}/helloworld.proto)
protobuf_generate(TARGET proto
                  IMPORT_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
                  PROTOC_OUT_DIR ${CMAKE_CURRENT_BINARY_DIR})

protobuf_generate(TARGET proto
                  LANGUAGE grpc
                  GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc
                  PLUGIN "protoc-gen-grpc=\$<TARGET_FILE:gRPC::grpc_cpp_plugin>"
                  IMPORT_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
                  PROTOC_OUT_DIR "${CMAKE_CURRENT_BINARY_DIR}")

target_link_libraries(proto PUBLIC protobuf::libprotobuf)
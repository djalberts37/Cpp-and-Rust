project(protobuf-cpp)
cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_FLAGS "-g -Wall")

find_package(Protobuf REQUIRED CONFIG)
find_package(gRPC REQUIRED)

add_subdirectory(proto)

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR} ${Protobuf_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} proto ${Protobuf_LIBRARIES} gRPC::grpc++)
add_dependencies(${PROJECT_NAME} proto)

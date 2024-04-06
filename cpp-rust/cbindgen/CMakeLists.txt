cmake_minimum_required(VERSION 3.20.0)
project(cpp-cbindgen-rust)

add_subdirectory(lib)

get_target_property(rustLib_dir cbindgen-rust LOCATION)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${rustLib_dir}/libcbindgen_rust.so cbindgen-rustLib)
add_dependencies(${PROJECT_NAME} cbindgen-rustLib cbindgen-rust)
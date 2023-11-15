project(cbindgen-rustLib)

find_program(CBINDGEN cbindgen REQUIRED)

# Set Cargo variable and Build type.
set(CARGO_CMD cargo build)
set(TARGET_DIR "debug")

# Set variable to path of rust shared library.
set(cbindgen-rustLib_SO "${CMAKE_CURRENT_BINARY_DIR}/${TARGET_DIR}/libcbindgen_rust.so")

# Calling Cargo to build rust library.
add_custom_target(cbindgen-rust ALL
    COMMENT "Compiling ${PROJECT_NAME} module. Calling Cargo..."
    COMMAND CARGO_TARGET_DIR=${CMAKE_CURRENT_BINARY_DIR} ${CARGO_CMD} 
    COMMAND cp ${cbindgen-rustLib_SO} ${CMAKE_CURRENT_BINARY_DIR}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(cbindgen-rust PROPERTIES LOCATION ${CMAKE_CURRENT_BINARY_DIR})

# Command that will call Cbindgen before build and generate header file.
add_custom_command(TARGET cbindgen-rust
    PRE_BUILD
    COMMAND ${CBINDGEN} ${CMAKE_CURRENT_SOURCE_DIR} -o ${CMAKE_CURRENT_SOURCE_DIR}/include/LibRust.hpp
    COMMENT "Generating header file from Rust lib.")

# Create library target that will be used by the executable to link to.
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE include)
add_dependencies(${PROJECT_NAME} cbindgen-rust)
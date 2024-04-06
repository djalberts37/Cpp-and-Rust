project(rust-autocxx-cpp)

# Set Cargo variable and Build type.
set(CARGO_CMD cargo build)

# Calling Cargo to build rust library.
add_custom_target(${PROJECT_NAME} ALL
    COMMENT "Compiling ${PROJECT_NAME} module. Calling Cargo..."
    COMMAND CARGO_TARGET_DIR=${CMAKE_CURRENT_BINARY_DIR} ${CARGO_CMD}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
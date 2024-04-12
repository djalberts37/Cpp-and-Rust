# Rust meets Cpp

This repository demonstrates integration of Rust components into a C++ project using various techniques, including Foreign Function Interface (FFI) and third-party communication, such as Protocol Buffers. Rust is a powerful system programming language known for its safety features and performance, while C++ is widely used in system-level programming. This README provides instructions for integrating Rust components into a C++ project using different methods.

(Side not: The presentation of the meetup can be found [here](doc/PPT%20C++%20RUST.pdf))

## Requirements

- [Visual Studio Code](https://code.visualstudio.com/) \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Extensions:
    - WSL (When on windows)
    - Dev Containers
- [Docker](https://docs.docker.com/get-docker/)

## How to Build and Try:

The Dev containers feature provide a consistent and reproducible environment including all dependencies when developing within Visual Studio Code (VS Code). In order to build and use a VS Code Dev container execute the following command:

```
Ctrl + Shift + p and then select -> Dev Containers: Rebuild Container
``` 

## How to build project:

When using the Dev Container, make sure that the repo is copied into the Dev Container volume:

```
git clone https://gitlab.com/djalberts/cpp-and-rust.git
```

Create a build directory

```
mkdir build_cpp-and-rust
```

Call CMake to generate the build files:

```
cmake -B build_cpp-and-rust -S cpp-and-rust
```

Build the entire project:

```
cmake --build build_cpp-and-rust/
```

## How to run the targets:

This section outlines how to run the different built targets.

### CPP-Rust

#### CBindgen

Change directory to `/home/developer/development/build_cpp-and-rust/cpp-rust/cbindgen/` and execute the following statement to run application developed in Cpp which uses Rust library.

```
./cpp-cbindgen-rust
```

(Side note: For more information about generating Rust interfacing to Cpp, take a look at [CBindgen](https://github.com/mozilla/cbindgen/blob/master/docs.md) crate.)

### Protobuf

Change directory to `/home/developer/development/build_cpp-and-rust/protobuf/cpp/`. From this directory, both the protobuf cpp server and client can be executed.

```
<!-- Client -->
./cpp-client/protobuf-cpp-client

<!-- Server -->
./cpp-server/protobuf-cpp-server
```

Change directory to `/home/developer/development/build_cpp-and-rust/protobuf/tonic-rust/debug`. From this directory, both the protobuf rust server and client can be executed.

```
<!-- Client -->
./helloworld-client

<!-- Server -->
./helloworld-server
```

(Side note: For more information, about creating a Rust gRPC client and server, take a look at the Rust [Tonic](https://github.com/hyperium/tonic/blob/master/README.md) crate.)

### Rust-CPP

#### Bindgen

Change directory to `/home/developer/development/build_cpp-and-rust/rust-cpp/bindgen/debug` and execute the following statement to run application developed in Rust which uses Cpp library through generated bindings with bindgen.

```
./rusty_car_factory
```

(Side note: For more information about generating Rust interfacing to Cpp, take a look at [Bindgen](https://rust-lang.github.io/rust-bindgen/introduction.html) crate.)

#### Autocxx

Change directory to `/home/developer/development/build_cpp-and-rust/rust-cpp/autocxx/debug` and execute the following statement to run application developed in Rust which uses Cpp library through generated bindings with autocxx.

```
./rust-autocxx-cpp
```

(Side note: For more information about generating Rust interfacing to Cpp, take a look at [Autocxx](https://google.github.io/autocxx/index.html) crate.)
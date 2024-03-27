# cpp-and-rust

## Overview

This repository demonstrates integration of Rust components into a C++ project using various techniques, including Foreign Function Interface (FFI) and third-party communication, such as Protocol Buffers. Rust is a powerful system programming language known for its safety features and performance, while C++ is widely used in system-level programming. This README provides instructions for integrating Rust components into a C++ project using different methods.

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



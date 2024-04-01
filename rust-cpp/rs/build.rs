use std::env;
use std::path::PathBuf;
use bindgen;

fn main() {
    cc::Build::new()
        .cpp(true)
        .file("../cpp/carfactory.cpp")
        .file("../cpp/car.cpp")
        .file("../cpp/component.cpp")
        .compile("cppcarfactory");

    println!("cargo::rerun-if-changed=../cpp/carfactory.cpp");
    println!("cargo::rerun-if-changed=../cpp/carfactory.hpp");
    println!("cargo::rerun-if-changed=../cpp/car.cpp");
    println!("cargo::rerun-if-changed=../cpp/car.hpp");
    println!("cargo::rerun-if-changed=../cpp/component.cpp");
    println!("cargo::rerun-if-changed=../cpp/component.hpp");


    // The bindgen::Builder is the main entry point
    // to bindgen, and lets you build up options for
    // the resulting bindings.
    let bindings = bindgen::Builder::default()
        .clang_arg("-std=c++20")
        .clang_arg("-x")
        .clang_arg("c++")
        // The input header we would like to generate
        // bindings for.
        .header("../cpp/carfactory.hpp")
        .enable_cxx_namespaces() // create a module for each c++ namespace
        .opaque_type("std::.*") // treat all c++ types as opaque
        .allowlist_type("cppfactory::Car") // use an allowlist to only generate for our own classes
        .allowlist_type("cppfactory::SteeringWheel")
        .allowlist_type("cppfactory::Wheel")
        // Tell cargo to invalidate the built crate whenever any of the
        // included header files changed.
        .parse_callbacks(Box::new(bindgen::CargoCallbacks::new()))
        // Finish the builder and generate the bindings.
        .generate()
        // Unwrap the Result and panic on failure.
        .expect("Unable to generate bindings");

    // Write the bindings to the $OUT_DIR/bindings.rs file.
    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");
}
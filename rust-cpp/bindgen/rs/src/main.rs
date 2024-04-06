
#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

use std::ffi::{CString, CStr};

use rand::Rng;

fn main() {
  println!("Welcome to the Rusty Car Factory, where you can put trust in Rust!");

  let brand = CString::new("Fjord").expect("CString::new failed");
  let model = CString::new("Rustang").expect("CString::new failed");

  unsafe {
    let mut car = root::cppfactory::Car::new(brand.as_ptr(), model.as_ptr());

    let car_brand = CStr::from_ptr(car.get_brand());
    let car_model = CStr::from_ptr(car.get_model());
    
    assert_eq!(brand, car_brand.into());
    assert_eq!(model, car_model.into());

    println!("We've successfully started construction on a new {} {}! [{:p}]", car_brand.to_str().unwrap_or("UNKNOWN"), car_model.to_str().unwrap_or("UNKNOWN"), &car);

    let has_steering = rand::random::<bool>();
    if has_steering {
      let steeringwheel = root::cppfactory::SteeringWheel::new();
      car.attach(&steeringwheel._base);
    }

    let max = rand::thread_rng().gen_range(0..5);

    for _ in 0..max {
      let wheel = root::cppfactory::Wheel::new();
      car.attach(&wheel._base);
    }

    car.assembly_report();

    root::cppfactory::Car_Car_destructor(&mut car);
  }
} 

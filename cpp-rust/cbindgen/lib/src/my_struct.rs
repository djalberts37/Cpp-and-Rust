use std::os::raw::c_int;

#[repr(C)]
pub struct MyStruct {
    pub prop1: c_int,
    pub prop2: c_int,
    pub prop3: c_int,
}

impl MyStruct {
    pub fn new(prop1: c_int, prop2: c_int, prop3: c_int) -> MyStruct {
        MyStruct { prop1, prop2, prop3 }
    }
}

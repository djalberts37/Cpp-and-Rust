mod my_struct;

use my_struct::MyStruct;
use std::os::raw::c_int;

#[no_mangle]
pub extern "C" fn add(left: i32, right: i32) -> i32 {
    left + right
}

#[no_mangle]
pub extern "C" fn sum_properties(s: *mut MyStruct) -> c_int {
    let temp_struct;

    unsafe {
        // Considered to be unsafe since dereference of raw pointer.
        temp_struct = &*s;
    }
    
    // Sum all properties of struct.
    temp_struct.prop1 + temp_struct.prop2 + temp_struct.prop3
}
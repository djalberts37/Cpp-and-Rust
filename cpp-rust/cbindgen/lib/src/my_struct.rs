#[repr(C)]
pub struct MyStruct {
    pub prop1: i32,
    pub prop2: i32,
    pub prop3: i32,
}

impl MyStruct {
    #[no_mangle]
    pub extern "C" fn new_struct(prop1: i32, prop2: i32, prop3: i32) -> MyStruct {
        MyStruct { prop1, prop2, prop3 }
    }
    
    #[no_mangle]
    pub extern "C" fn sum_properties(&mut self) -> i32 {
        // Sum all properties of struct.
        self.prop1 + self.prop2 + self.prop3
    }

    #[no_mangle]
    pub extern "C" fn modulo(&mut self, x : i32) -> bool {
        (self.prop1 + self.prop2 + self.prop3) % x == 0
    }
}
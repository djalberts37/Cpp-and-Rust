#include <iostream>
#include "LibRust.hpp"

int main(int argc, char* argv[]) 
{ 
    int result = ffi::add(3, 5);
    std::cout << "Adding up from Rust library = " << result << std::endl;
    
    // Two approaches to instantiate a Rust object.
    // ffi::MyStruct myStruct{10, 20, 30};
    ffi::MyStruct myStruct = ffi::new_struct(10, 20, 30);
    int32_t sum = ffi::sum_properties(&myStruct);
    std::cout << "Sum of properties: " << sum << std::endl;

    bool ret = ffi::modulo(&myStruct, 3);
    std::cout << "Modulo? : " << std::boolalpha << ret << std::endl;
    return 0;
}

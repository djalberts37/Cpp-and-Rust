#include <iostream>
#include <cstdint>
#include "LibRust.hpp"

int main(int argc, char* argv[]) 
{ 
    int result = ffi::add(3, 5);
    std::cout << "Adding up from Rust library = " << result << std::endl;
    
    ffi::MyStruct myStruct{10, 20, 30};
    int32_t sum = ffi::sum_properties(&myStruct);
    std::cout << "Sum of properties: " << sum << std::endl;
    return 0;
}

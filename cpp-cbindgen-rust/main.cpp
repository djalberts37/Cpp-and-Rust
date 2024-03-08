#include <iostream>
#include "LibRust.hpp"

int main(int argc, char* argv[]) 
{ 
    int result = add(3, 5);
    std::cout << "Adding up from Rust library = " << result << std::endl;
}
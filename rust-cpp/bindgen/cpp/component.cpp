
#include <iostream>

#include "component.hpp"

namespace cppfactory {
  
Component::Component(const char* type) : type(type) {
//  std::cout << "C++> Component::Component(" << type << ")\n";
}

Component::~Component() {
//  std::cout << "C++> Component::~Component(" << type << ")\n";
}
    
const char* Component::get_type() const {
  return type;
}

} // namespace cppfactory

#include "carfactory.hpp"

namespace cppfactory {
  
SteeringWheel::SteeringWheel() : Component("Steering Wheel") {
}

SteeringWheel::~SteeringWheel() {

}

bool SteeringWheel::is_valid_component_for(const Car* car) const {
  auto& parts = car->get_components();

  return std::any_of(
    parts.begin(), 
    parts.end(), 
    [&](const Component* p) { 
      return typeid(p) == typeid(SteeringWheel); 
    }
  );
}

Wheel::Wheel() : Component("Wheel") {
}

Wheel::~Wheel() {

}

bool Wheel::is_valid_component_for(const Car* car) const {
  auto& parts = car->get_components();

  return 4 >= std::count_if(
    parts.begin(), 
    parts.end(), 
    [&](const Component* p) { 
      return typeid(p) == typeid(Wheel); 
    }
  );
}

} // namespace cppfactory 

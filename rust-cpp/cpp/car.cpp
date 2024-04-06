#include <iostream>
#include <unordered_map>

#include "car.hpp"

namespace cppfactory {
  
Car::Car(const char* brand, const char* model) : brand(brand), model(model) {
  auto b = get_brand();
  auto m = get_model();
  std::cout << "Constructing a new " << b << " " << m << ", exciting! [" << std::hex << (this) << "]\n";
}

Car::~Car() {
  auto b = get_brand();
  auto m = get_model();
  std::cout << "Alas, our beloved " << b << " " << m << " has unfortunately ended up in the scrapyard!\n";
}

const char* Car::get_brand() const {
  return brand;
}

const char* Car::get_model() const {
  return model;
}

bool Car::attach(const Component* component) {
  //std::cout << "C++> Going to try and attach a " << component->get_type() << " to our " << get_brand() << " " << get_model() << " [" << std::hex << (this) << "]\n";
  
  if (!component->is_valid_component_for(this))
    return false;
  
  components.push_back(component);
  return true;
}

const Car::component_list_t& Car::get_components() const {
  return components;
}

void Car::assembly_report() const {
  std::unordered_map<std::string, int> seen;

  std::cout << "So far the car has amassed " << components.size() << " part(s); ";
  for (auto& c : components) {
    std::string key = std::string(c->get_type());
    seen[key]++;
  }

  for (auto& kvp : seen) {
    std::cout << kvp.second << "x " << kvp.first << ", ";
  }

  std::cout << "all in all, pretty neat!\n";
}

} // namespace cppfactory



#pragma once
#include <string>

namespace cppfactory {
  
class Car;

class Component {
  public:
    Component(const char* type);
    virtual ~Component();
    
    virtual bool is_valid_component_for(const Car* car) const = 0;
    const char* get_type() const;

  private:
    const char* type;
};

} // namespace cppfactory

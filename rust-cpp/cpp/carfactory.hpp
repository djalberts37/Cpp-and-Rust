#include "car.hpp"
#include "component.hpp"

namespace cppfactory {
  
class SteeringWheel : public Component {
  public:
    SteeringWheel();
    virtual ~SteeringWheel();

    bool is_valid_component_for(const Car* car) const;
};

class Wheel : public Component {
  public:
    Wheel();
    virtual ~Wheel();

    bool is_valid_component_for(const Car* car) const;
};

} // namespace cppfactory


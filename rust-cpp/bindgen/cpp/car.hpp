#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stdexcept>

#include "component.hpp"

namespace cppfactory {

class Car {
  public:
    typedef std::vector<const Component*> component_list_t;

  public:
    Car(const char* brand, const char* model);
    virtual ~Car();

    const char* get_brand() const;
    const char* get_model() const;
    bool attach(const Component* component);
    const component_list_t& get_components() const;

    void assembly_report() const;

  private:
    const char* brand;
    const char* model;

    component_list_t components;
};

}

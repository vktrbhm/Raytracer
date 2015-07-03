#include "shape.hpp"

//Con-/Destructor
shape::shape()
  : color_{0,0,0}
  , name_{"default"}{
  std::cout << name_ << ": call shape default constructor" << std::endl;
}

shape::shape(Color const& color, std::string const& name)
  : color_{color}
  , name_{name}{
  std::cout << name_ << ": call shape user defined constructor" << std::endl;
}

shape::~shape(){
  std::cout << name_ << ": call shape destructor" << std::endl;
}

//Getter
Color shape::getcolor() const {
  return color_;
}

std::string shape::getname() const {
  return name_;
}

// Methods
std::ostream& shape::print(std::ostream& os) const {
  os << "shape( name=>\"" << name_ << "\", "
     << "color=>(" << color_.r << "," << color_.g << "," << color_.b << ") )"<<'\n';
  return os;
}

std::ostream& operator<<(std::ostream& os, shape const& s) {
  return s.print(os);
}
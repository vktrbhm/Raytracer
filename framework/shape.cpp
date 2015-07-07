#include "shape.hpp"

//Con-/Destructor
Shape::Shape()
  : color_{0,0,0}
  , name_{"default"}{
  std::cout << name_ << ": call shape default constructor" << std::endl;
}

Shape::Shape(Color const& color, std::string const& name)
  : color_{color}
  , name_{name}{
  std::cout << name_ << ": call shape user defined constructor" << std::endl;
}

Shape::~Shape(){
  std::cout << name_ << ": call shape destructor" << std::endl;
}

//Getter
Color Shape::getcolor() const {
  return color_;
}

std::string Shape::getname() const {
  return name_;
}

// Methods
std::ostream& Shape::print(std::ostream& os) const {
  os << "shape( name=>\"" << name_ << "\", "
     << "color=>(" << color_.r << "," << color_.g << "," << color_.b << ") )"<<'\n';
  return os;
}

std::ostream& operator<<(std::ostream& os, shape const& s) {
  return s.print(os);
}
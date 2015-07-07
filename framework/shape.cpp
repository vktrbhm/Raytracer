#include "shape.hpp"

//Con-/Destructor
Shape::Shape()
  : mat_{Material{}}
  , name_{"default Shape"}{
  std::cout << name_ << ": call shape default constructor" << std::endl;
}

Shape::Shape(Material const& mat, std::string const& name)
  : mat_{mat}
  , name_{name}{
  std::cout << name_ << ": call shape user defined constructor" << std::endl;
}

Shape::~Shape(){
  std::cout << name_ << ": call shape destructor" << std::endl;
}

//Getter
Material Shape::getmaterial() const {
  return mat_;
}

std::string Shape::getname() const {
  return name_;
}

// Methods
std::ostream& Shape::print(std::ostream& os) const {
  os << "shape( name=>\"" << name_ << "\", "
     << "Material =>(" << mat_.getname() <<'\n';
  return os;
}

std::ostream& operator<<(std::ostream& os, Shape const& s) {
  return s.print(os);
}
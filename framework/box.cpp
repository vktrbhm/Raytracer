#include "box.hpp"

#include <cmath>
#include <glm/glm.hpp>

// Con-/Destructor
box::box()
  : shape{}
  , min_{0,0,0}
  , max_{0,0,0}{
  std::cout << name_ << ": call box default constructor" << std::endl;
}

box::box(glm::vec3 const& min, glm::vec3 const& max)
	: shape{}
	, min_{min}
	, max_{max}{
	std::cout << name_ << ": call box user defined constructor 1" << std::endl;
}

box::box(glm::vec3 const& min, glm::vec3 const& max, Color const& color,
         std::string const& name)
  : shape{color, name}
  , min_{min}
  , max_{max}{
  std::cout << name_ << ": call box user defined constructor 2" << std::endl;
}

box::~box(){
  std::cout << name_ << ": call box destructor" << std::endl;
}

// Getter
glm::vec3 box::getmin() const {
	return min_;
}

glm::vec3 box::getmax() const {
	return max_;
}

// Methods
std::ostream& box::print(std::ostream& os) const {
  os << "box( ";
  shape::print(os);
  os << ", min=>(" << min_.x << "," << min_.y << "," << min_.z << "), "
     << "max=>(" << max_.x << "," << max_.y << "," << max_.z << ") )";
  return os;
}

float box::area() const {
  return 2*std::fabs(max_.x - min_.x)*std::fabs(max_.y - min_.y) +
         2*std::fabs(max_.x - min_.x)*std::fabs(max_.z - min_.z) +
         2*std::fabs(max_.y - min_.y)*std::fabs(max_.z - min_.z);
}

float box::volume() const {
  return (max_.x - min_.x)*
         (max_.y - min_.y)*
         (max_.z - min_.z);
}


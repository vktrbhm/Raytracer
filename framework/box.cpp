#include "box.hpp"

#include <cmath>
#include <glm/glm.hpp>

// Con-/Destructor
Box::Box()
  : Shape{}
  , min_{0,0,0}
  , max_{0,0,0}{
  std::cout << name_ << ": call box default constructor" << std::endl;
}

Box::Box(glm::vec3 const& min, glm::vec3 const& max)
	: Shape{}
	, min_{min}
	, max_{max}{
	std::cout << name_ << ": call box user defined constructor 1" << std::endl;
}

Box::Box(glm::vec3 const& min, glm::vec3 const& max, Material const& mat,
         std::string const& name)
  : Shape{mat, name}
  , min_{min}
  , max_{max}{
  std::cout << name_ << ": call box user defined constructor 2" << std::endl;
}

Box::~Box(){
  std::cout << name_ << ": call box destructor" << std::endl;
}

// Getter
glm::vec3 Box::getmin() const {
	return min_;
}

glm::vec3 Box::getmax() const {
	return max_;
}

// Methods
std::ostream& Box::print(std::ostream& os) const {
  os << "box( ";
  Shape::print(os);
  os << ", min=>(" << min_.x << "," << min_.y << "," << min_.z << "), "
     << "max=>(" << max_.x << "," << max_.y << "," << max_.z << ") )";
  return os;
}

float Box::area() const {
  return 2*std::fabs(max_.x - min_.x)*std::fabs(max_.y - min_.y) +
         2*std::fabs(max_.x - min_.x)*std::fabs(max_.z - min_.z) +
         2*std::fabs(max_.y - min_.y)*std::fabs(max_.z - min_.z);
}

float Box::volume() const {
  return (max_.x - min_.x)*
         (max_.y - min_.y)*
         (max_.z - min_.z);
}

bool Box::intersect(Ray const& ray, float& t) {

}


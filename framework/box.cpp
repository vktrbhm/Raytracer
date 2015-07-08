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

bool Box::intersect(Ray const& ray, float& t) const {

  glm::vec3 dirfrac{0,0,0};
  // Normalize the Ray
  glm::vec3 r = glm::normalize(ray.direction_);
  dirfrac.x = 1.0f / r.x;
  dirfrac.y = 1.0f / r.y;
  dirfrac.z = 1.0f / r.z;



  float t1 = (min_.x - ray.origin_.x) * dirfrac.x;
  float t2 = (max_.x - ray.origin_.x) * dirfrac.x;
  float t3 = (min_.y - ray.origin_.y) * dirfrac.y;
  float t4 = (max_.y - ray.origin_.y) * dirfrac.y;
  float t5 = (min_.z - ray.origin_.z) * dirfrac.z;
  float t6 = (max_.z - ray.origin_.z) * dirfrac.z;

  float tmin = std::max(
    std::max(std::min(t1,t2), std::min(t3,t4)), std::min(t5,t6));

  float tmax = std::min(
    std::min(std::max(t1,t2), std::max(t3,t4)), std::max(t5,t6));

  if (tmax < 0) {
    t = tmax;

    std::cout << "------Box Is behind us---------------" << t << std::endl; 
    std::cout << "Distance: " << t << std::endl; 
    std::cout << "---------------------" << t << std::endl; 

    return t;
  }

  if (tmin > tmax) {
    t = tmax;

    std::cout << "---------No Intersect------------" << t << std::endl; 
    std::cout << "Distance: " << t << std::endl; 
    std::cout << "---------------------" << t << std::endl; 

    return t; 
  }

  t = tmin;

    std::cout << "----------Right in the Box-----------" << t << std::endl; 
    std::cout << "Distance: " << t << std::endl; 
    std::cout << "---------------------" << t << std::endl; 

  return t;
}


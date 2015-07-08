#include "sphere.hpp"

// COn-/Destructor
Sphere::Sphere()
  : Shape{}
  , center_{0,0,0}
  , radius_{1}{
  std::cout << name_ << ": call sphere default constructor" << std::endl;
}

Sphere::Sphere(glm::vec3 const& center, float radius)
	: Shape{}
	, center_{center}
	, radius_{radius}{
	std::cout << name_ << ": call sphere user defined constructor_1" << std::endl;	
}

Sphere::Sphere(glm::vec3 const& center, float radius, Material const& mat, std::string const& name)
  : Shape{mat, name}
  , center_{center}
  , radius_{radius}{
  std::cout << name_ << ": call sphere user defined constructor_2" << std::endl;
}

Sphere::~Sphere(){
  std::cout << name_ << ": call sphere destructor" << std::endl;
}

// Getter
glm::vec3 Sphere::getcenter() const {
	return center_;
}

float Sphere::getradius() const {
	return radius_;
}

// Methods
std::ostream& Sphere::print(std::ostream& os) const {
  os << "sphere( ";
  Shape::print(os);
  os << ", center=>(" << center_.x << "," << center_.y << "," << center_.z << "), "
     << "radius=>" << radius_ << " )"<<'\n';
  return os;
}

float Sphere::area() const {
  return 4*M_PI*pow(radius_,2);
}

float Sphere::volume() const {
  return (4/3.0f)*M_PI*pow(radius_,3);
}



bool Sphere::intersect(Ray const& ray, float& t) const {
  auto n_ray = glm::normalize(ray.direction_);
  bool intersects = glm::intersectRaySphere(ray.origin_, n_ray, center_, radius_*radius_, t);
	
  std::cout << "---------------------" << t << std::endl; 
  std::cout << "Distance: " << t << std::endl; 
  std::cout << "---------------------" << t << std::endl; 


	return t;
}

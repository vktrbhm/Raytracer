#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP

#include "shape.hpp"
#include "ray.hpp"

#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include <glm/vec3.hpp>
#include <cmath>

class Sphere : public Shape
{
public:
  // Con-/Destructor
  Sphere();
  Sphere(glm::vec3 const& center, float radius);
  Sphere(glm::vec3 const& center, float radius, Material const& mat, std::string const& name);
  ~Sphere();

  // Getter
  glm::vec3 getcenter() const;
  float getradius() const;

  // Methods
  std::ostream& print(std::ostream& os) const override;
  float area() const override;
  float volume() const override;

  bool intersect(Ray const& ray, float& t) const override ;

private:
  glm::vec3 center_;
  float radius_;
};

#endif // BUW_SPHERE_HPP
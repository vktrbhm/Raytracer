#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP

#include "shape.hpp"
#include "ray.hpp"

#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include <glm/vec3.hpp>
#include <cmath>

class sphere : public shape
{
public:
  // Con-/Destructor
  sphere();
  sphere(glm::vec3 const& center, float radius);
  sphere(glm::vec3 const& center, float radius, Color const& color, std::string const& name);
  ~sphere();

  // Getter
  glm::vec3 getcenter() const;
  float getradius() const;

  // Methods
  std::ostream& print(std::ostream& os) const override;
  float area() const override;
  float volume() const override;

  bool intersect(ray const& ray, float& ) const;

private:
  glm::vec3 center_;
  float radius_;
};

#endif // BUW_SPHERE_HPP
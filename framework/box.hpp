#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP

#include "shape.hpp"
#include "ray.hpp"

#include <glm/vec3.hpp>

class Box : public Shape
{
public:
  // Con-/Destructor
  Box();
  Box(glm::vec3 const& min, glm::vec3 const& max);
  Box(glm::vec3 const& min, glm::vec3 const& max, Material const& mat, std::string const& name);
  ~Box();

  // Getter const ref!!
  glm::vec3 getmin() const;
  glm::vec3 getmax() const;

  // Methods
  std::ostream& print(std::ostream& os) const;
  float area() const override;
  float volume() const override;
  std::pair<bool,float> intersect(Ray const& ray, float& t) const override;
  
private:
  glm::vec3 min_;
  glm::vec3 max_;
};

#endif // BUW_BOX_HPP
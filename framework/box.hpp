#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP

#include "shape.hpp"
#include "ray.hpp"

#include <glm/vec3.hpp>

class box : public shape
{
public:
  // Con-/Destructor
  box();
  box(glm::vec3 const& min, glm::vec3 const& max);
  box(glm::vec3 const& min, glm::vec3 const& max, Color const& color,
      std::string const& name);
  ~box();

  // Getter const ref!!
  glm::vec3 getmin() const;
  glm::vec3 getmax() const;

  // Methods
  std::ostream& print(std::ostream& os) const;
  float area() const override;
  float volume() const override;
  
private:
  glm::vec3 min_;
  glm::vec3 max_;
};

#endif // BUW_BOX_HPP
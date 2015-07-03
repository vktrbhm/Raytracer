#ifndef BUW_RAY_HPP
#define BUW_RAY_HPP

#include <glm/vec3.hpp>

struct ray
{
  ray(glm::vec3 const& o, glm::vec3 const& d)
    : origin_{o}
    , direction_{d}
  {}

  glm::vec3 origin_;
  glm::vec3 direction_;
};

#endif // BUW_RAY_HPP
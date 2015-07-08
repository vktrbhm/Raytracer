#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP

#include "material.hpp"
#include "ray.hpp"

#include <string>

class Shape
{
public:
  // Con-/Destructor
  Shape();
  Shape(Material const& mat, std::string const& name);                                         
  virtual ~Shape();

  // Getter
  Material getmaterial() const;
  std::string getname() const;

  // Methods
  virtual float area() const = 0;
  virtual float volume() const = 0;
  virtual std::pair<bool,float> intersect(Ray const& ray,float& t) const = 0; 
  //virtual bool intersect(Ray const& ray, float& t) = 0;
  virtual std::ostream& print(std::ostream& os) const;


  friend std::ostream& operator<<(std::ostream& os, Shape const& s);

protected:
  Material mat_;
  std::string name_;
};

#endif // BUW_SHAPE_HPP
#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP

#include "color.hpp"

#include <string>

class Shape
{
public:
  // Con-/Destructor
  Shape();
  Shape(Color const& color, std::string const& name);

   ~Shape();                                        // Weglassen von "virtual" -> Methode wird verdeckt
  //virtual ~shape();

  // Getter
  Color getcolor() const;
  std::string getname() const;

  // Methods
  virtual float area() const = 0;
  virtual float volume() const = 0;
  virtual bool intersect(Ray const& ray, float& t) = 0;
  virtual std::ostream& print(std::ostream& os) const;


  friend std::ostream& operator<<(std::ostream& os, shape const& s);

protected:
  Color color_;
  std::string name_;
};

#endif // BUW_SHAPE_HPP
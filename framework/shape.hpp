#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP

#include "color.hpp"

#include <string>

class shape
{
public:
  // Con-/Destructor
  shape();
  shape(Color const& color, std::string const& name);

   ~shape();                                        // Weglassen von "vitual" -> Methode wird verdeckt
  //virtual ~shape();

  // Getter
  Color getcolor() const;
  std::string getname() const;

  // Methods
  virtual float area() const = 0;
  virtual float volume() const = 0;

  virtual std::ostream& print(std::ostream& os) const;
  friend std::ostream& operator<<(std::ostream& os, shape const& s);

protected:
  Color color_;
  std::string name_;
};

#endif // BUW_SHAPE_HPP
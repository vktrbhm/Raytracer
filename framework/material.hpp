#ifndef BUW_MATERIAL_HPP
#define BUW_MATERIAL_HPP

#include <string>
#include <iostream>

#include "color.hpp"


class Material {
public:
	// Con-/Destructor
	Material();
	Material(std::string const& name, Color const& ka, Color const& kd, Color const& ks, float m);
	~Material();

	//Methods
	std::string getname() const;
	Color getKA() const;
	Color getKD() const;
	Color getKS() const;
	float getM() const;


private:

	std::string name_;		// Name des Materials
	Color ka_;				// Ambienter Reflexionskoeffizient
	Color kd_;				// Diffuser Reflexionskoeffizient
	Color ks_;				// Spiegelungs Reflexionskoeffizient
	float m_;				// Spiegelungseigenschaften

};


#endif // BUW_MATERIAL_HPP
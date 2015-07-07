#include "material.hpp"

// Con-/Destructors

Material::Material() 
	: name_{"Default Material"}
	, ka_{1,1,1}
	, kd_{1,1,1}
	, ks_{1,1,1}
	, m_{10} {

	}
	 

Material::Material(std::string const& name, Color const& ka, Color const& kd, Color const& ks, float m) 
	: name_{name}
	, ka_{ka}
	, kd_{kd}
	, ks_{ks}
	, m_{m} {

	}

Material::~Material(){}

// Methods

std::string Material::getname() const {
	return name_;
}

Color Material::getKA() const {
	return ka_;
}

Color Material::getKD() const {
	return kd_;
}

Color Material::getKS() const {
	return ks_;
}

float Material::getM() const {
	return m_;
}

std::ostream& Material::print(std::ostream& os) const {
	os << "Material( name=>\"" << name_ << "\", "
  	<< "Ambienter Reflexionskoeffizient ka =>(" << ka_.r << "," << ka_.g << "," << ka_.b << ") )"<<'\n'
	<< "Diffuser Reflexionskoeffizient kd =>(" << kd_.r << "," << kd_.g << "," << kd_.b << ") )"<<'\n'
	<< "Spiegelungs Reflexionskoeffizient ks =>(" << ks_.r << "," << ks_.g << "," << ks_.b << ") )"<<'\n'
	<< "Spiegelungskoeffizien m =>(" << m_ <<'\n';	
  return os;
}

std::ostream& operator<<(std::ostream& os, Material const& mat) {
  return mat.print(os);
}


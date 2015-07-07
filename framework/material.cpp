#include "material.hpp"

// Con-/Destructors

Material::Material() 
	: name_ = {"default"}, ka_ = {1,1,1},kd_ = {1,1,1}, ks_ = {1,1,1}, m_ = {10} {} 


Material::Material(std::string const& name, Color const& ka, Color const& kd, Color const& ks, float m) 
	: name_{name}, ka_{ka}, kd_{kd}, ks_{ks}, m_{m} {}

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


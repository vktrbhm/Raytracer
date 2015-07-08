#include "scene.hpp"

Scene::Scene() : materials_{} {};

void Scene::addMaterial(std::string const& name, Color const& ka, Color const& kd, Color const& ks, float m) {
	materials_.push_back(Material{name, ka, kd, ks, m});
}

void Scene::printMaterial() const {
	for (auto i : materials_) {
		std::cout << i << std::endl;
	}
}

#ifndef BUW_SCENE_HPP
#define BUW_SCENE_HPP

#include "color.hpp"
#include "material.hpp"

#include <iterator>
#include <map>
#include <memory>
#include <string>
#include <vector>

struct Scene
{
	Scene();
	
	void addMaterial(std::string const& name, Color const& ka, Color const& kd, Color const& ks, float m);
	void printMaterial() const;

	std::vector<Material> materials_;
};



#endif //BUW_SCENE_HPP
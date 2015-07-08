#include "sdfloader.hpp"

SDFloader::SDFloader(std::string const& filename)
	: filename_{filename}
	{
		object_.open(filename_, std::ifstream::in);
		if(!object_.is_open()) {
			std::cout << "Can't open file" << filename_ << "\"." << std::endl;
		}
		else {
			std::cout << "File \"" << filename_ << "\" opened." << std::endl;
		}
	}

SDFloader::~SDFloader(){
	object_.close();
}

std::vector<std::string>& SDFloader::split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;

	while (std::getline(ss, item, delim)) {
		if (! item.empty()) {
			elems.push_back(item);
		}
	}
	return elems;
}

Scene& SDFloader::load(Scene& scene) {
	std::string line;
	std::vector<std::string> v;

	while ( getline(object_,line)) {
		v = split(line, ' ', v);

		if (!line.empty()) {
			if (v[0] == "define") {
				if (v[1] == "material") {
					scene.addMaterial( v[2],
						Color{std::stof(v[3]), std::stof(v[4]), std::stof(v[5])},
						Color{std::stof(v[6]), std::stof(v[7]), std::stof(v[8])},
						Color{std::stof(v[9]), std::stof(v[10]), std::stof(v[11])},
						std::stof(v[12])
						);
				}
			}
		}
		v.clear();	
	}
	return scene;
}
#ifndef BUW_SDFLOADER_HPP
#define BUW_SDFLOADER_HPP

#include "scene.hpp"

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

class SDFloader
{
public:
	SDFloader(std::string const& filename);
	~SDFloader();

	std::vector<std::string>& split(const std::string &s, char delim, std::vector<std::string> &elems);

	Scene& load(Scene& scene);

private:
	std::string filename_;
	std::ifstream object_;

};


#endif //BUW_SDFLOADER_HPP
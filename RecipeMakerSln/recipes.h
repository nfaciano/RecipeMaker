#pragma once
#include <string>
#include <vector>
#include "Ingredients.h"
class recipesL {
private:
	std::vector<ingredients> iList;
	std::string name;
	std::string directions;

public:
	recipesL(std::vector<ingredients> iList, std::string name, std::string directions);
	std::vector<ingredients> getiList() const { return iList; }
	std::string getName() const { return name; }
	std::string getDirections() const { return directions; }
	void setName(std::string name);
	void setIlist(std::vector<ingredients> iList);
	void setDirections(std::string directions);





};
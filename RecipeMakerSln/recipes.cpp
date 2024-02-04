#include "recipes.h"


recipesL::recipesL(std::vector<ingredients> iList, std::string name, std::string directions) {
	this->iList = iList;
	this->name = name;
	this->directions = directions;
}

void recipesL::setName(std::string name) {
	this->name = name;
}
void recipesL::setDirections(std::string directions) {
	this->directions = directions;
}
void recipesL::setIlist(std::vector<ingredients> iList) {
	this->iList = iList;
}


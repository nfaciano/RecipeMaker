#include "functions.h"
#include <fstream> 
#include <sstream>

std::vector<ingredients> functions::readIngredientsFromFile(const std::string& filepath) {

	std::ifstream file(filepath);
	if (file.is_open() && file.peek() != std::ifstream::traits_type::eof()) {
		std::string line;
		std::vector<std::string> temp;
		while (std::getline(file, line)) {
			std::string value;
			std::stringstream line_stream(line);
			while (std::getline(line_stream, value, ',')) {
				temp.push_back(value);
			}
			for (unsigned int i = 0; i < temp.size(); i += 3) {
				double amount = std::stof(temp[i]);
				ingredients ingredient(amount, temp[i + 1], temp[i + 2]);
				fridge.push_back(ingredient);
			}

		}

	}
	else {
		std::cout << "Error: Unable to open file" << std::endl;
	}
	file.close();
	return fridge;
}


std::vector<std::vector<ingredients>> functions::readIngredientsForRecipes(const std::string& filepath) {
	std::vector<std::vector<ingredients>> iList;
	std::ifstream file(filepath);

	if (file.is_open() && file.peek() != std::ifstream::traits_type::eof()) {
		std::string line;
		std::vector<std::string> temp;
		while (std::getline(file, line)) {
			std::vector<std::string> temp;
			std::string value;
			std::stringstream line_stream(line);
			std::vector<ingredients> tempL;
			while (std::getline(line_stream, value, ',')) {
				temp.push_back(value);
			}
			for (unsigned int i = 0; i < temp.size(); i += 3) {
				double amount = std::stof(temp[i]);
				ingredients ingredient(amount, temp[i + 1], temp[i + 2]);
				tempL.push_back(ingredient);

			}
			iList.push_back(tempL);
		}

	}
	else {
		std::cout << "Error: Unable to open file" << std::endl;
	}
	file.close();
	return iList;
}

std::vector<recipesL> functions::readRecipes(const std::string& filepath) {
	std::vector<std::vector<ingredients>> ingredientsList = readIngredientsForRecipes("Recipes.txt");

	std::vector<recipesL> recipes;
	std::ifstream file(filepath);

	std::string line;
	std::string name, directions;
	while (std::getline(file, line)) {
		if (line == "###") {
			if (!name.empty() && !directions.empty()) {
				recipesL recipe(ingredientsList[recipes.size()], name, directions);
				recipes.push_back(recipe);
				name = "";
				directions = "";
			}
		}
		else if (name.empty()) {
			name = line;
		}
		else {
			directions += line + '\n';
		}
	}

	if (!name.empty() && !directions.empty()) {
		recipesL recipe(ingredientsList[recipes.size()], name, directions);
		recipes.push_back(recipe);
	}

	return recipes;
}












void functions::writeIngredientsToFile(const std::string& filename, const std::vector<ingredients>& ingredientsList) { //ingredients for fridge
	std::ofstream outputfile(filename);
	for (const auto& ingredients : ingredientsList) {
		outputfile << ingredients.getAmount() << "," << ingredients.getUnit() << "," << ingredients.getName() << ",";

	}
	outputfile.close();
}

void functions::writeRecipesToFile3(const std::string& filepath, const std::vector<recipesL>& recipes) {
	std::ofstream file(filepath);
	if (file.is_open()) {
		for (unsigned int i = 0; i < recipes.size(); i++) {
			file << recipes[i].getName()<<std::endl << "###" << std::endl << recipes[i].getDirections() << std::endl <<
				"###" << std::endl;

		}
		file.close();
	}
	else {
		std::cout << "Error: Unable to open file" << std::endl;
	}
}//directions for recipes





void functions::writeIngredientsToFile2(const std::string& filepath, const std::vector<recipesL>& recipesList) { //ingredients for recipes
	std::ofstream file(filepath);


	if (file.is_open()) {
		for (int i = 0; i < recipes.size(); i++) {
			std::vector<ingredients> iList = recipes[i].getiList();
			for (int j = 0; j < iList.size(); j++) {
				file << iList[j].getAmount() << "," << iList[j].getUnit() << "," << iList[j].getName();
				if (iList.size() - 1 != j) {
					file << ',';
				}
			}
			file << std::endl;
		}
	}
	else {
		std::cout << "Error: Unable to open file" << std::endl;
	}
	file.close();
}
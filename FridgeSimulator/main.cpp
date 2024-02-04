#include "Header.h"
#include <fstream> 
#include <sstream>
#include <algorithm>
#include <cctype>
#include <limits>


void giveOptions() {
	std::cout << "Please choose from the options below:" << std::endl;
	std::cout << "1.) List Your Ingredients" << std::endl;
	std::cout << "2.) Add an Ingredient" << std::endl;
	std::cout << "3.) Review Your Recipes" << std::endl;
	std::cout << "4.) Add Recipe" << std::endl;
	std::cout << "5.) List Makeable Recipes" << std::endl;
	std::cout << "6.) Choose Recipe to Make" << std::endl;
	std::cout << "7.) Edit Ingredient" << std::endl;
	std::cout << "8.) Edit Recipe" << std::endl;
	std::cout << "9.) Exit" << std::endl;
	std::cout << "Choice: ";
}
void readFile(std::vector<std::string>& fridge, std::string& filename) {

	std::ifstream file(filename);
	if (!file) {
		std::ofstream new_file(filename);
		new_file << "temp,for,you";
		new_file.close();
	}
	
	
	std::string line;
	while (std::getline(file, line)) {
		std::string value;
		std::stringstream line_stream(line);
		while (std::getline(line_stream, value, ',')) {
			fridge.push_back(value);
		}
	}
	
}
void writeFile(std::string outPutFile, std::vector<std::string>& fridge) {

	std::ofstream file(outPutFile);

	for (size_t i = 0; i < fridge.size(); i++) {
		file << fridge[i] << ",";
	}
}
void readRecipes(std::vector<std::vector<std::string>>& recipes, std::string& filename) {

	std::ifstream file(filename);
	std::string line;

	while (std::getline(file, line)) {
		std::vector<std::string> row;
		std::stringstream lineStream(line);
		std::string cell;

		while (std::getline(lineStream, cell, ',')) {
			row.push_back(cell);
		}

		recipes.push_back(row);
	}

	
}
void writeRecipes(std::vector<std::vector<std::string>>& recipes, std::string& filename) {
	std::ofstream outputfile(filename);
	for (const auto& vec : recipes) {
		for (const auto& element : vec) {
			outputfile << element << ",";
		}
		outputfile << std::endl;
	}
}
std::vector<std::vector<std::string>> refreshValues(std::vector<std::vector<std::string>>& recipes,recipeTest recipeTest) {
	std::vector<std::vector<std::string>> recipesConvert;
	for (unsigned int i = 0; i < recipes.size(); i++) {
		std::vector<std::string> yn;
		yn.push_back(recipes[i][0]);
		for (unsigned int j = 1; j < recipes[i].size() - 1; j += 3) {
			yn.push_back(recipeTest.convert(recipes[i][j + 1], recipes[i][j]));
			yn.push_back(recipes[i][j + 1]);
			yn.push_back(recipes[i][j + 2]);

		}
		recipesConvert.push_back(yn);
	}
	return recipesConvert;
}


int main() {
	std::string choice;
	std::vector<std::vector<std::string>> recipes,recipesConvert;
	std::vector<std::string> fridge,avalRecipes,copyrecipes;
	std::string fridge1 = "Fridge.txt",recipes1 = "Recipes.txt";
	readFile(fridge,fridge1);
	readRecipes(recipes, recipes1);
	recipeTest recipeTest(fridge, recipes);
	std::cout << "Hello welcome to your fridge! Press enter to continue! " << std::endl;
	std::cin.get();
	recipesConvert = refreshValues(recipes,recipeTest);
	while (choice != "9") {
		system("cls");
		giveOptions();
		std::getline(std::cin, choice);
		if (choice.size() == 1) {
			if (choice == "1") {
				recipeTest.listIngredients(fridge);
				std::cout << "Press enter to continue: ";
				std::cin.get();

			}
			if (choice == "2") {
				fridge = recipeTest.getIngredient(fridge);
				std::cin.get();
			}

			if (choice == "3") {
				recipeTest.listAllRecipes(recipes);
				std::cin.get();
			}
			if (choice == "4") {
				recipes = recipeTest.addRecipe(recipes);
				recipesConvert = refreshValues(recipes, recipeTest);
			}
			if (choice == "5") {
				avalRecipes = recipeTest.listRecipes(recipesConvert, fridge);
				for (unsigned int i = 0; i < avalRecipes.size(); i++) {
					std::cout << i + 1 << ".) " << avalRecipes[i] << std::endl;
				}
				std::cout << "Here is your list of avaliabe recipes with the ingredients in your fridge. Please press enter to continue: " << std::endl;
				std::cin.get();
			}
			if (choice == "6") {
				fridge = recipeTest.chooseRecipe(recipesConvert, fridge, recipes);
				std::cin.get();
			}
			if (choice == "7") {
				fridge = recipeTest.editIngredient(fridge);
				std::cin.get();
			}
			if (choice == "8") {
				recipes = recipeTest.editRecipe(recipes);
				recipesConvert = refreshValues(recipes, recipeTest);
				std::cin.get();
			}

		}
	
		
	}
	writeFile(fridge1, fridge);
	writeRecipes(recipes, recipes1);


}
#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <iostream>

class recipeTest {
private:
	std::vector<std::string> fridge;
	std::vector<std::vector<std::string>> recipes,recipesConvert;
	std::string unit, ingredient, amount,name;
	
public:
	recipeTest(std::vector<std::string> Ffridge, std::vector<std::vector<std::string>> Frecipes);
	void listIngredients(std::vector<std::string> fridge);
	std::vector<std::string> getIngredient(std::vector<std::string> fridge);// adds an ingredient such as, ingredient[0] = ingredient, ingredient[1] = amount, ingredient[2] = unit
	std::vector<std::vector<std::string>>  addRecipe(std::vector<std::vector<std::string>> recipes); // adds a recipe in this format , recipe[0] = ingredient, recipe[1] = amount, recipe[2] = unit
	void listAllRecipes(std::vector<std::vector<std::string>> recipes);
	std::vector<std::string> listRecipes(std::vector<std::vector<std::string>> recipesConvert, std::vector<std::string> fridge); //lists the recipes that are avaliable from the fridge
	std::vector<std::string> chooseRecipe(std::vector<std::vector<std::string>> recipes, std::vector<std::string> fridge, std::vector<std::vector<std::string>> data); //gets user recipe and deletes contents from fridge
	std::vector<std::string> convertUnitTo(std::vector<std::string> fridge,std::string unit,float amount,int place,char del);
	std::string convert(std::string unit,std::string amount);
	std::vector<std::string> editIngredient(std::vector<std::string> fridge);
	std::vector<std::vector<std::string>> editRecipe(std::vector<std::vector<std::string>> recipes);




};
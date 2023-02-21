#pragma once
#include "Ingredients.h"
#include "recipes.h"
#include <vector>
#include <iostream>
#include <string>
#include <iostream>
#include <fstream> 
#include <sstream>
#include <wx/wx.h>
#include "wx/button.h"


class functions {
private:
	std::vector<ingredients> fridge;
	std::vector<recipesL> recipes;


public:
	//constructors
	wxTextCtrl* testInput;
	wxChoice* unitInput;
	wxListBox* ingredientListBox;
	functions();
	
	//getters
	std::vector<ingredients> getFridge() const { return fridge; }
	std::vector<recipesL> getRecipes() const { return recipes; }
	std::vector<ingredients> addFridge(ingredients temp);
	
	//setters
	std::vector<ingredients> setAmount(int place, double amount);
	
	//read
	std::vector<ingredients> readIngredientsFromFile(const std::string& filepath);
	std::vector<std::vector<ingredients>>  readIngredientsForRecipes(const std::string& filepath);
	std::vector<recipesL> readRecipes(const std::string& filepath);
	//write
	void writeIngredientsToFile(const std::string& filename, const std::vector<ingredients>& ingredientsList);
	void writeRecipesToFile3(const std::string& filename, const std::vector<recipesL>& recipesList);
	void writeIngredientsToFile2(const std::string& filename, const std::vector<recipesL>& recipesList);



	//functions
	void addIngredient(wxWindow* parent);
	void listIngredients(wxWindow* parent);


	void listRecipes(wxWindow* parent,char makeable);
	void showRecipe(wxWindow* parent, int index, std::vector<recipesL>& recipes);
	std::vector<recipesL> findMakeableRecipes();
	void addRecipe(wxWindow* parent);
	void editValues(wxWindow* parent,int &selection,char FoR, int iListSelection);
	void makeRecipe(wxWindow* parent);
	void editRecipe(wxWindow* parent,int &selection);

	void displayInstructions(wxWindow* parent);


	//secondary functions
	std::string doubleToStringAndFraction(double number);
	int gcd(int a, int b);
	void makeRecipeFunction(recipesL recipe);




};
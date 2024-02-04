#include "Header.h"
#include <sstream>
#include <algorithm>
#include <cctype>
#include <iomanip>
recipeTest::recipeTest(std::vector<std::string> Ffridge, std::vector<std::vector<std::string>> Frecipes) {
	Ffridge = fridge;
	Frecipes = recipes;

}

void recipeTest::listIngredients(std::vector<std::string> fridge) {
	system("cls"); //clear console
	unsigned int counter = 0;
	if (fridge.size() != 0) {
		for (unsigned int i = 0; i < fridge.size(); i +=3) {
			counter++;
			std::cout<< counter << ".) " << fridge[i] << ' ' << fridge[i + 1] << ' ' << fridge[i + 2] << ' ' << std::endl; //list ingredients in fridge
		}
		std::cout << "Here is your list of ingredients!" << std::endl;
	}
	else {
		std::cout << "Your fridge is empty. Please add some ingredients" << std::endl; //if no items print this
	}

}

std::vector<std::string> recipeTest::convertUnitTo(std::vector<std::string> fridge, std::string unit,float amount,int place, char del) {
	//takes input - fridge - unit of old unit(to convert to cups) - amount - place of new unit wanted to converse to - 'n' or no
	std::string mainUnit = fridge[place];
	float d = 0;
	if (unit == "CUPS" or unit == "CUP") { // Unit conversion table that turns all inputs into cups to be manipulated
		amount = amount;
	}
	if (unit == "FLOZ" or unit == "FLOZS") {
		amount /= 10;
	}
	if (unit == "ML" or unit == "MLS") {
		amount /= 568;
	}
	if (unit == "PINT" or unit == "PINTS") {
		amount *= 10;
	}
	if (unit == "QUART" or unit == "QUARTS") {
		amount *= 5;
	}
	if (unit == "TBSP" or unit == "TBSPS") {
		amount /= 16;
	}
	if (unit == "TSP" or unit == "TSPS") {
		amount /= 48;
	}
	if (unit == "OUNCE" or unit == "OUNCES") {
		amount = amount;
	}
	if (unit == "GRAM" or unit == "GRAMS") {
		amount /= 28;
	}
	if (unit == "POUND" or unit == "POUNDS") {
		amount *= 16;
	}
	if (unit == "MG" or unit == "MGS") {
		amount /= 28350;
	}
	std::string amount2 = fridge[place - 1]; //common variable
	//mainunit is the unit that is chosen by the user when entering the ingredient. this will convert from cups to the main unit of the ingredient
	//units of volumes
	if (mainUnit == "CUPS" or mainUnit == "CUP") {
		if (del == 'n') { // if del == 'n' then the function is being called in terms of adding an ingredient
			 d = std::stof(amount2) + (amount);
		}
		else {
			 d = amount; //otherwise its being called when the amount is being entered back into the vector from cups to the main unit
		}
		std::stringstream ss;
		ss << std::fixed << std::setprecision(3) << d;
		std::string s = ss.str();
		fridge[place - 1] = s;
		return fridge;

	}
	if (mainUnit == "FLOZ" or mainUnit == "FLOZS") {
		if (del == 'n') {
			 d = std::stof(amount2) + (amount * 8.115);
		}
		else {
			 d = amount * 8.115;
		}
		std::stringstream ss;
		ss << std::fixed << std::setprecision(3) << d;
		std::string s = ss.str();
		fridge[place - 1] = s;
		return fridge;
	}
	if (mainUnit == "ML" or mainUnit == "MLS") {
		if (del == 'n') {
			 d = std::stof(amount2) + (amount * 240);
		}
		else {
			 d = amount * 240;

		}
		std::stringstream ss;
		ss << std::fixed << std::setprecision(3) << d;
		std::string s = ss.str();
		fridge[place - 1] = s;
				std::cout << fridge[place - 1];

		return fridge;
	}
	if (mainUnit == "PINT" or mainUnit == "PINTS") {
		if (del == 'n') {
			d = std::stof(amount2) + (amount / 240);
		}
		else {
			d = amount / 240;
		}
		std::stringstream ss;
		ss << std::fixed << std::setprecision(3) << d;
		std::string s = ss.str();
		fridge[place - 1] = s;
		return fridge;
	}
	if (mainUnit == "QUART" or mainUnit == "QUARTS") {
		if (del == 'n') {
			d = std::stof(amount2) + (amount / 3.943);
		}
		else {
			d = amount / 3.943;

		}
		std::stringstream ss;
		ss << std::fixed << std::setprecision(3) << d;
		std::string s = ss.str();
		fridge[place - 1] = s;
		return fridge;
	}
	if (mainUnit == "TBSP" or mainUnit == "TBSPS") {
		if (del == 'n') {
			d = std::stof(amount2) + (amount * 16.231);
		}
		else {
			d = amount * 16.231;
		}
		std::stringstream ss;
		ss << std::fixed << std::setprecision(3) << d;
		std::string s = ss.str();
		fridge[place - 1] = s;
		return fridge;
	}
	if (mainUnit == "TSP" or mainUnit == "TSPS") {
		if (del == 'n') {
			d = std::stof(amount2) + (amount * 48.692);
		}
		else {
			d = amount * 48.692;
		}
		std::stringstream ss;
		ss << std::fixed << std::setprecision(3) << d;
		std::string s = ss.str();
		fridge[place - 1] = s;
		return fridge;
	}
	//units of volume
	if (mainUnit == "OUNCE" or  mainUnit  == "OUNCES") {
		if (del == 'n') {
			d = std::stof(amount2) + (amount);
		}
		else {
			d = amount;
		}
		std::stringstream ss;
		ss << std::fixed << std::setprecision(3) << d;
		std::string s = ss.str();
		fridge[place - 1] = s;
		return fridge;
	}
	if (mainUnit == "GRAM" or mainUnit == "GRAMS") {
		if (del == 'n') {
			d = std::stof(amount2) + (amount / 28);
		}
		else {
			d = amount / 28;
		}
		std::stringstream ss;
		ss << std::fixed << std::setprecision(3) << d;
		std::string s = ss.str();
		fridge[place - 1] = s;
		return fridge;
	}
	if (mainUnit == "POUND" or mainUnit == "POUNDS") {
		if (del == 'n') {
			 d = std::stof(amount2) + (amount / 16);
		}
		else {
			 d = amount / 16;

		}
		std::stringstream ss;
		ss << std::fixed << std::setprecision(3) << d;
		std::string s = ss.str();
		fridge[place - 1] = s;
		//std::cout << fridge[place - 1] << "WOHOO" << amount << std::endl;

		return fridge;
	}
	if (mainUnit == "MG" or mainUnit == "MGS") {
		std::string amount2 = fridge[place - 1];
		if (del == 'n') {
			d = std::stof(amount2) + (amount * 28350);
		}
		else {
			d = amount * 28350;
		}
		std::stringstream ss;
		ss << std::fixed << std::setprecision(3) << d;
		std::string s = ss.str();
		fridge[place - 1] = s;
		return fridge;
	}
	if (del == 'n') {
		d = std::stof(amount2) + (amount);
	}
	else {
		d = amount;
	}
	std::stringstream ss;
	ss << std::fixed << std::setprecision(3) << d;
	std::string s = ss.str();
	fridge[place - 1] = s;
	fridge[place] = mainUnit;
	return fridge;
}

std::vector<std::string> recipeTest::getIngredient(std::vector<std::string> fridge) {
	system("cls");
	std::string choice = "y";

	while (choice == "y" or choice == "y") { //keeps looping until user is done adding ingredients
		std::cout << "Please enter the ingredient in the format - Amount Unit Ingredient" << std::endl; // prompts user to store unit properly
		std::cout << "The unit that you entered will be the ingredients main unit " << std::endl;		
		std::string line;
		int found = 0;
		std::getline(std::cin, line);

		if (line.empty()) {
			break;
		}
		std::istringstream iss(line);
		std::getline(iss, ingredient);
		size_t pos = ingredient.find(' '); //have to do a bunch of splitting and spring manipulation to properly take in input due to spaces in the ingredients
		if (pos != std::string::npos) { 
			amount = ingredient.substr(0, pos);
			ingredient = ingredient.substr(pos + 1);
			pos = ingredient.find(' ');
			if (pos != std::string::npos) {
				unit = ingredient.substr(0, pos);
				ingredient = ingredient.substr(pos + 1);
			}
			else {
				unit = ingredient;
				ingredient.clear();
			}
		}
		std::transform(unit.begin(), unit.end(), unit.begin(), //turns everything to uppercase to avoid case sensitivity
			[](unsigned char c) { return std::toupper(c); });

		std::transform(ingredient.begin(), ingredient.end(), ingredient.begin(), // ^
			[](unsigned char c) { return std::toupper(c); });
		if (ingredient.size() == 0) {
			ingredient = unit;
			unit = ""; //if there is no unit entered then the ingredient is saved as the unit, so must fix that and add empty string as placeholder for unit
		}
		for (unsigned int i = 2; i < fridge.size(); i += 3) {
			if (ingredient == fridge[i]) { //go until ingredient is found in fridge, if it is.
				found = i;
				float amnt = stof(amount);
				fridge = convertUnitTo(fridge, unit, amnt, i - 1,'n'); //this will add the correct amount to the amount stored in the fridge
				break;
			}

		}

		if (found == 0) { //if not found add that item
			if (ingredient.size() == 0) { //still must consider no unit items
				fridge.push_back(amount);
				fridge.push_back("");
				fridge.push_back(ingredient);
			}
			else {
				fridge.push_back(amount); //sets initial amount as 0 so it can
				fridge.push_back(unit); //stores as "mainunit"
				fridge.push_back(ingredient);

			}
		}
		std::cout << "Would you like to enter another ingredient?" << std::endl;
		std::cout << "Y/N: ";
		std::getline(std::cin, choice); //continue loop ?
		
	}
	std::cout << "You have added ingredients to your fridge. Press enter to continue: " << std::endl;


	return fridge;
}


std::string recipeTest::convert(std::string unit,std::string amount) {
	//function that takes in a unit and amount and turns it into cups. used to compare variables later with same unit.
	if (unit == "CUPS" or unit == "CUP") {
		float d = std::stof(amount);
		std::stringstream ss;
		ss << std::fixed << std::setprecision(3) << d;
		std::string s = ss.str();

		return s;
	}
	if (unit == "FLOZ" or unit == "FLOZS") {
		float d = std::stof(amount);
		d /= 10;
		std::stringstream ss;
		ss << std::fixed << std::setprecision(3) << d;
		std::string s = ss.str();

		return s;
	}
	if (unit == "ML" or unit == "MLS") {
		float d = std::stof(amount);
		d /= 568;
		std::stringstream ss;
		ss << std::fixed << std::setprecision(3) << d;
		std::string s = ss.str();

		return s;
	}
	if (unit == "PINT" or unit == "PINTS") {
		float d = std::stof(amount);
		d *=  10;
		std::stringstream ss;
		ss << std::fixed << std::setprecision(3) << d;
		std::string s = ss.str();

		return s;
	}
	if (unit == "QUART" or unit == "QUARTS") {
		float d = std::stof(amount);
		d *= 5;
		std::stringstream ss;
		ss << std::fixed << std::setprecision(3) << d;
		std::string s = ss.str();

		return s;
	}
	if (unit == "TBSP" or unit == "TBSPS") {
		float d = std::stof(amount);
		d /= 16;
		std::stringstream ss;
		ss << std::fixed << std::setprecision(3) << d;
		std::string s = ss.str();

		return s;
	}
	if (unit == "TSP" or unit == "TSPS") {
		float d = std::stof(amount);
		d /= 48;
		std::stringstream ss;
		ss << std::fixed << std::setprecision(3) << d;
		std::string s = ss.str();

		return s;
	}
	if (unit == "OUNCE" or unit == "OUNCES") {
		float d = std::stof(amount);
		std::stringstream ss;
		ss << std::fixed << std::setprecision(3) << d;
		std::string s = ss.str();

		return s;
	}
	if (unit == "GRAM" or unit == "GRAMS") {
		float d = std::stof(amount);
		d /= 28;
		std::stringstream ss;
		ss << std::fixed << std::setprecision(3) << d;
		std::string s = ss.str();

		return s;
	}
	if (unit == "POUND" or unit == "POUNDS") {
		float d = std::stof(amount);
		d *= 16;
		std::stringstream ss;
		ss << std::fixed << std::setprecision(3) << d;
		std::string s = ss.str();

		return s;
	}
	if (unit == "MG" or unit == "MGS") {
		float d = std::stof(amount);
		d /= 28350;
		std::stringstream ss;
		ss << std::fixed << std::setprecision(3) << d;
		std::string s = ss.str();

		return s;
	}
	if (unit == "NA") {
		float d = std::stof(amount);
		d /= 16;
		std::stringstream ss;
		ss << std::fixed << std::setprecision(3) << d;
		std::string s = ss.str();

		return s;
	}

	float d = std::stof(amount);
	std::stringstream ss;
	ss << std::fixed << std::setprecision(3) << d;
	std::string s = ss.str();

	return s;
}

std::vector<std::vector<std::string>>  recipeTest::addRecipe(std::vector<std::vector<std::string>>  recipes) {
	system("cls");
	std::cout << "Please enter the recipe with one ingredient at a time. - press enter when finished" << std::endl;
	std::cout << "Enter as follows: Amount - Unit - Ingredient" << std::endl;
	std::cout << "What is the recipe name? Type Exit to go back" << std::endl; //exit case is exit
	std::cout << "Recipe: ";
	std::vector<std::string> tempRecipe; 
	std::getline(std::cin, name);
	std::transform(name.begin(), name.end(), name.begin(), //take in name for recipe and turn it to uppercase
		[](unsigned char c) { return std::toupper(c); });
	if (name == "EXIT") { //yktv
		return recipes;
	}
	for (unsigned int i = 0; i < recipes.size(); i++) {
		if (recipes[i][0] == name) { //check to see if there is already a recipe, cannot differentiate between if so.
			std::cout << "This recipe is already in your cookbook.";
			return recipes;
		}
	}
	tempRecipe.push_back(name); // this must mean there is no recipe so time to create it, name is stored once
	while (true) {
		std::string line;
		std::getline(std::cin, line);

		if (line.empty()) {
			break;
		}
		std::istringstream iss(line);
		std::getline(iss, ingredient); //same deal as ingredients i must take in consideration spaces for the ingredient so i have to make a whole string manipulation fn
		size_t pos = ingredient.find(' ');
		if (pos != std::string::npos) {
			amount = ingredient.substr(0, pos);
			ingredient = ingredient.substr(pos + 1);
			pos = ingredient.find(' ');
			if (pos != std::string::npos) {
				unit = ingredient.substr(0, pos);
				ingredient = ingredient.substr(pos + 1);
			}
			else {
				unit = ingredient;
				ingredient.clear();
			}
		}
		std::transform(unit.begin(), unit.end(), unit.begin(),
			[](unsigned char c) { return std::toupper(c); });

		std::transform(ingredient.begin(), ingredient.end(), ingredient.begin(),
			[](unsigned char c) { return std::toupper(c); });
		if (ingredient.size() == 0) { //if no empty enter empty string so it can be compared
			tempRecipe.push_back(amount);
			tempRecipe.push_back("");
			tempRecipe.push_back(unit);
		}
		else {
			tempRecipe.push_back(amount); //otherwise just act as normal
			tempRecipe.push_back(unit);
			tempRecipe.push_back(ingredient);
		}
	}
	recipes.push_back(tempRecipe);

	return recipes;


}

std::vector<std::string> recipeTest::listRecipes(std::vector<std::vector<std::string>> recipes, std::vector<std::string> fridge) {
	system("cls");
	std::vector<std::string> avalrecipes; 
	for (unsigned int i = 0; i < recipes.size(); i++) {
		bool found = true;

		while (found) {
			for (unsigned int j = 3; j < recipes[i].size(); j += 3) {
				int place = 0;
				bool check = false;
				std::string item = recipes[i][j]; //ingredient to see if is in fridge is equal to "item" - goes through look for every item in said recipe
				for (unsigned int k = 2; k < fridge.size(); k += 3) {
					if (item == fridge[k]) { //simple comparison to see if "item" is in fridge. if so continue
						check = true;
						place = k;
						break;
					}
				}
				if (!check) {
					found = false; //in any case where the item is not found break the loop and go to the next recipe
					break;
				}
				std::string item3 = fridge[place - 2]; //otherwise we must check to see if amount in fridge is greater than amount needed in recipe
				std::string unit3 = fridge[place - 1];
				std::string count4 = convert(unit3, item3);
				std::string count3 = recipes[i][j - 2];
				float count1 = std::stof(count3);
				float count2 = std::stof(count4);
				if (count1 > count2) {
					found = false; //if so return false
				}
			}
			break;
		}
		if (found) {
			avalrecipes.push_back(recipes[i][0]); //if all conditions met then pushback to new vector with list of possible recipes
		}
	
		
	}
	return avalrecipes;
	
}

void recipeTest::listAllRecipes(std::vector<std::vector<std::string>>  recipes) {
	system("cls");
	std::string choice;
	if (recipes.size() > 0) {
		for (unsigned int i = 0; i < recipes.size(); i++) {
			std::cout << i+1 << ".) " << recipes[i][0];
			std::cout << std::endl;
		} //first lists all the recipes
		std::cout << "Type in your desired recipes name or type 'n' to exit" << std::endl;
		std::getline(std::cin, choice); //takes in user input to see selected recipe
		system("cls");
		std::string word = choice;

		if (word != "n") { // user enters n if they want to return to menu
			
			std::transform(word.begin(), word.end(), word.begin(),
				[](unsigned char c) { return std::toupper(c); }); //must turn to uppercase
			for (unsigned int i = 0; i < recipes.size(); i++) {
				if (word == recipes[i][0]) { //go until we find the recipe in the recipes vector
					for (unsigned int j = 1; j < recipes[i].size(); j += 3) {
						if (recipes[i][j+1] != "") {
							std::cout << recipes[i][j] << ' ' << recipes[i][j + 1] << " of " << recipes[i][j + 2] << std::endl; //when found print the ingredients
						}
						else {
							std::cout << recipes[i][j] << ' ' << recipes[i][j + 2] << std::endl; //if no unit then dont cout the unit, there is none!
						}
						
					}

				}
			}
		}
	}
	else {
		std::cout << "You have no recipes. Please add some" <<std::endl; //if recipes have no items
	}
	std::cout << "Press enter to continue: " << std::endl; // -_-
}

std::vector<std::string> recipeTest::chooseRecipe(std::vector<std::vector<std::string>> recipesConvert, std::vector<std::string> fridge, std::vector<std::vector<std::string>> data){
	system("cls");
	std::vector<std::string> avalRecipes = listRecipes(recipesConvert, fridge); //simple way to find avaliable recipes using previous function
	std::cout << "Here are a list of avaliable recipes to choose from: " << std::endl;
	if (avalRecipes.size() != 0) { // if there are recipes
		for (unsigned int i = 0; i < avalRecipes.size(); i ++) {
			std::cout <<i+1 << ".) " << avalRecipes[i] << std::endl; //lists the avaliable recipes
		}

	}
	else {
		std::cout << "You cannot make any of your recipes :( " << std::endl; // there are no recipes execute this
		return fridge;
	}
	std::string recipeword;
	int place;
	bool found = false;
	std::cout << "Please enter a valid recipe name: " << std::endl;
	std::getline(std::cin, recipeword); //user chooses recipe that gets turned to uppercase to compare
	std::transform(recipeword.begin(), recipeword.end(), recipeword.begin(),
		[](unsigned char c) { return std::toupper(c); });
	for (unsigned int i = 0; i < recipesConvert.size(); i++) {
		if (recipesConvert[i][0] == recipeword) { //when the recipe is found the index for that recipe is stored into variable place
			place = i;
			found = true;
			break;
		}
	}
	if (!found) {
		std::cout << "This recipe is not avaliable. " << std::endl; //if the recipe is found, "found" will be true and this wont execute
		return fridge;
	}
	std::cout << "Here is the recipe for: " << recipeword << std::endl; // we found the recipe!
	for (unsigned int i = 1; i < data[place].size(); i+=3) {
			if (data[place][i+1] != "") {
				std::cout << data[place][i] << ' ' << data[place][i + 1] << " of " << data[place][i + 2] << std::endl;
			}
			else {
				std::cout << data[place][i] << ' ' << data[place][i + 2] << std::endl; //prints recipe
			}

	}
	std::string yn;
	std::cout << "Would you like to make the recipe? " << std::endl;
	std::cout << "Y/N: ";
	getline(std::cin, yn); //asks user if they want to make the recipe after reviewing it
	yn[0] = tolower(yn[0]); // easier to evaluate
	if (yn[0] == 'y') {
		for (unsigned int i = 3; i < recipesConvert[place].size(); i += 3) {
			for (unsigned int j = 2; j < fridge.size(); j += 3) {
				if (recipesConvert[place][i] == fridge[j]) {
					std::string amount1 = recipesConvert[place][i - 2]; //amount1 = amount needed in recipe
					std::string amount2 = fridge[j - 2]; // amount2 = amount left in fridge
					std::string amount2Unit = fridge[j - 1]; // gets unit in fridge
					amount2 = convert(amount2Unit, amount2); // uses fridge unit and amount to convert it to cups
					float amnt1 = std::stof(amount1);  //since the recipesconverted is already all in cups we dont need to do anything
					float amnt2 = std::stof(amount2);
					float d = amnt2 - amnt1; //simple math
					if (d == 0) {
						fridge.erase(fridge.begin() + j - 2, fridge.begin() + j + 1); //if there are no items left delete the ingredient from fridge
					}
					else {
						if (amount2Unit == "OUNCE" or amount2Unit == "GRAM" or amount2Unit == "MG" or amount2Unit == "OUNCE" or amount2Unit == "POUND" or
							amount2Unit == "OUNCES" or amount2Unit == "GRAMS" or amount2Unit == "MGS" or amount2Unit == "OUNCES" or amount2Unit == "POUNDS") { //otherwise check if it falls under mass catagory
							std::string finalunit = "OUNCES"; //all mass ingredients are evaluated in ounces
							fridge = convertUnitTo(fridge, finalunit, d, j - 1, 'd'); //enter new amount back into fridge, but must convert to the mainunit of ingredient first. no 'n' so it doesnt add the ingredient
							break;
						}
						if (amount2Unit == "ML" or amount2Unit == "QUART" or amount2Unit == "PINT" or amount2Unit == "FLOZ" or amount2Unit == "CUP" or amount2Unit == "TBSP" or amount2Unit == "TSP" or
							amount2Unit == "MLS" or amount2Unit == "QUARTS" or amount2Unit == "PINTS" or amount2Unit == "FLOZS" or amount2Unit == "CUPS" or amount2Unit == "TBSPS" or amount2Unit == "TSPS") { //checks to see if unit is volume
							std::string finalunit = "CUPS"; //all volume evaluated in cups
							fridge = convertUnitTo(fridge, finalunit, d, j - 1, 'd'); //enters new amount back into fridge
							break;
						}
						else {
							fridge = convertUnitTo(fridge, amount2Unit, d, j - 1, 'd'); //no units so no conversion needed.
							break;
						}
					}
						
					break;


				}
			}
		}

		std::cout << "Recipe made! " << std::endl; //success!
	}
	std::cout << "Please press enter to return to the menu ";
	return fridge;

}

std::vector<std::string> recipeTest::editIngredient(std::vector<std::string> fridge) {
	listIngredients(fridge); //lists all of the ingredients first for a easy view
	std::string choice,choice2;
	int place = 0;
	std::cout << "Hello please enter a number from the options below" << std::endl;
	std::cout << "1.) Type 1 remove the entire ingredient" << std::endl;
	std::cout << "2.) Type 2 to edit the amount of the ingredient" << std::endl;
	std::cout << "3.) Type 3 to edit the unit of the ingredient" << std::endl;
	std::cout << "Selection: ";
	std::getline(std::cin, choice); //get choice
	if (choice.size() == 1) { //if choice is not one of the choices then dont continue
		if (choice == "1" or choice == "2" or choice == "3") { // ^
			std::cout << "Please enter the ingredient name: " << std::endl; //gets ingredient wanted to modify
			std::getline(std::cin, choice2);
			std::transform(choice2.begin(), choice2.end(), choice2.begin(),
				[](unsigned char c) { return std::toupper(c); });
			for (unsigned int i = 2; i < fridge.size(); i += 3) {
				if (choice2 == fridge[i]) {
					place = i; //finds where that ingredient is in the fridge
					break;
				}
			}
			if (place == 0) {
				std::cout << "Ingredient not found. "; //if not found then return
				return fridge;
			}
			if (choice == "1") {
				fridge.erase(fridge.begin() + place - 2, fridge.begin() + place + 1); //erases entire vector from index of ingredient - 2 to +1
				system("cls");
				std::cout << choice2 << " Has been erased. Press enter to continue";
				return fridge;
			}
			if (choice == "2") {
				std::string amount;
				std::cout << "Please enter the new amount: " << std::endl;
				std::getline(std::cin, amount);
				fridge[place - 2] = amount; //changes amount of ingredient in fridge
				system("cls");
				std::cout << choice2 << "'s amount has been changed. Press enter to continue";
				return fridge;
			}
			if (choice == "3") {
				std::string unit;
				std::cout << "Please enter the new Unit: " << std::endl;
				std::getline(std::cin, unit);
				std::transform(unit.begin(), unit.end(), unit.begin(),
					[](unsigned char c) { return std::toupper(c); });
				std::string oldUnit = fridge[place - 1];
				float amounter = std::stof(fridge[place - 2]);
				fridge[place - 1] = unit;
				fridge = convertUnitTo(fridge, oldUnit, amounter, place-1, 'f');
				system("cls");
				std::cout << choice2 << "'s unit has been changed. Press enter to continue"; //changes unit and converts at same time
				return fridge;

			}
		}
		else {
			std::cout << "Please enter a valid selection";
		}
	}
	else {
		std::cout << "Please enter a valid selection";
	}
	return fridge;
	
}

std::vector<std::vector<std::string>> recipeTest::editRecipe(std::vector<std::vector<std::string>> recipes) {
	system("cls");
	std::string choice,choice2;
	int place,place2;
	bool found;
	std::cout << "Please choose from the list below: " << std::endl;
	std::cout << "1.) Remove recipe" << std::endl;
	std::cout << "2.) Remove ingredient in recipe" << std::endl;
	std::cout << "3.) Change amount in recipe" << std::endl;
	std::cout << "4.) Change unit in ingredient" << std::endl;
	std::cout << "Selection: ";
	std::getline(std::cin, choice);
	if (choice.size() == 1) {
		if (choice == "1" or choice == "2" or choice == "3" or choice == "4") {
			std::cout << "Here is your list of recipes: " << std::endl;
			for (unsigned int i = 0; i < recipes.size(); i++) {
				std::cout << i + 1 << ".) " << recipes[i][0];
				std::cout << std::endl;
			}
			std::cout << std::endl << "Please enter the name of the recipe you would like to modify: " <<std::endl;
			std::getline(std::cin, choice2);
			std::transform(choice2.begin(), choice2.end(), choice2.begin(),
				[](unsigned char c) { return std::toupper(c); });
			for (unsigned int i = 0; i < recipes.size(); i++) {
				if (choice2 == recipes[i][0]) {
					place = i;
					found = true;
					break;
				}
			}
			if (found) {
				if (choice == "1") {
					recipes.erase(recipes.begin() + place);
					system("cls");
					std::cout << "Recipe Deleted. Press enter to continue";
					return recipes;
				}
				for (unsigned int j = 1; j < recipes[place].size(); j += 3) {
					if (recipes[place][j + 1] != "") {
						std::cout << recipes[place][j] << ' ' << recipes[place][j + 1] << " of " << recipes[place][j + 2] << std::endl;
					}
					else {
						std::cout << recipes[place][j] << ' ' << recipes[place][j + 2] << std::endl;
					}

				}
				std::cout << "Please choose an ingredient to modify: " << std::endl;
				std::string choice3;
				std::getline(std::cin, choice3);
				std::transform(choice3.begin(), choice3.end(), choice3.begin(),
					[](unsigned char c) { return std::toupper(c); });
				for (unsigned int i = 3; i < recipes[place].size(); i += 3) {
					if (choice3 == recipes[place][i]) {
						place2 = i;
						break;
					}
				}
				if (place2 == 0) {
					std::cout << "Invalid ingredient" << std::endl;
					return recipes;
				}
				std::vector<std::string> temp;
				for (unsigned int i = 0; i < recipes[place].size(); i++) {
					temp.push_back(recipes[place][i]);
				}
				if (choice == "2") {
					recipes.erase(recipes.begin() + place);
					temp.erase(temp.begin() + place2 - 2, temp.begin() + place2 + 1);
					recipes.push_back(temp);
					system("cls");
					std::cout << "Ingredient deleted. Press enter to continue";
					return recipes;
				}
				if (choice == "3") {
					std::string amount;
					std::cout << "Please enter your new amount: " << std::endl;
					std::getline(std::cin, amount);
					temp[place2 - 2] = amount;
					recipes.erase(recipes.begin() + place);
					recipes.push_back(temp);
					system("cls");
					std::cout << "The amount has been changed. Press enter to continue";
					return recipes;
				}
				if (choice == "4") {
					std::string unit;
					std::cout << "Please enter your new unit: " << std::endl;
					std::getline(std::cin, unit);
					std::transform(unit.begin(), unit.end(), unit.begin(),
						[](unsigned char c) { return std::toupper(c); });
					temp[place2 - 1] = unit;
					recipes.erase(recipes.begin() + place);
					recipes.push_back(temp);
					system("cls");
					std::cout << "The unit has been changed. Press enter to continue";
					return recipes;
				}
			}
			else {
				std::cout << "Invalid choice " << std::endl;
				return recipes;
			}
		}
		else {
			std::cout << "Invalid choice " << std::endl;
			return recipes;
		}

	}
	else {
		std::cout << "Invalid choice " << std::endl;
		return recipes;
	}
	return recipes;
}

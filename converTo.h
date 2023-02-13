#pragma once
#include "Ingredients.h"

double ingredients::converToC(ingredients ingredient, ingredients newIngredient, char del) {
	std::string unit = ingredient.getUnit();
	double amount = ingredient.getAmount();
	std::string mainUnit = newIngredient.getUnit();
	double amount2 = newIngredient.getAmount(); //common variable
	double d = 0;

	if (unit == "ml" or unit == "") { // Unit conversion table that turns all inputs into cups to be manipulated
		amount = amount;
	}
	else if (unit == "fl oz") {
		amount *= 29.574;
	}
	else if (unit == "c") {
		amount *= 236.6;
	}
	else if (unit == "pt") {
		amount *= 473.2;
	}
	else if (unit == "qt") {
		amount *= 946.4;
	}
	else if (unit == "gal") {
		amount *= 3785;
	}
	else if (unit == "tbsp") {
		amount *= 14.787;
	}
	else if (unit == "tsp") {
		amount *= 4.929;
	}
	else if (unit == "L") {
		amount *= 1000;
	}

	if (del == 'e') {
		convertBackTo(mainUnit,amount);
		return amount;
	}
		//mainunit is the unit that is chosen by the user when entering the ingredient. this will convert from cups to the main unit of the ingredient
	//units of volumes
		if (mainUnit == "c") {
			if (del == 'n') { // if del == 'n' then the function is being called in terms of adding an ingredient
				d = (amount2 * 236.6) + (amount);
				convertBackTo(unit, d);
			}
			else {
				d = amount - amount2 * 236.6; //otherwise its being called when the amount is being entered back into the vector from cups to the main unit
				convertBackTo(unit, d);

			}
			return d;

		}
		if (mainUnit == "L") {
			if (del == 'n') {
				d = (amount2 * 1000) + (amount);
				convertBackTo(unit, d);
			}
			else {
				d = amount - amount2 * 1000;
				convertBackTo(unit, d);

			}
			return d;
		}
		if (mainUnit == "fl oz") {
			if (del == 'n') {
				d = (amount2 * 29.574) + (amount);
				convertBackTo(unit, d);
			}
			else {
				d = amount - amount2*29.574;
				convertBackTo(unit, d);

			}
			
			return d;
		}
		if (mainUnit == "ml" or unit == "") {
			if (del == 'n') {
				d = (amount2)+(amount);
				convertBackTo(unit, d);
			}
			else {
				d = amount - amount2;
			}
			return d;
		}
		if (mainUnit == "pt") {
			if (del == 'n') {
				d = (amount2 * 473.2) + (amount);
				convertBackTo(unit, d);
			}
			else {
				d = amount - amount2 * 473.2;
				convertBackTo(unit, d);

			}
			return d;
		}
		if (mainUnit == "qt") {
			if (del == 'n') {
				d = (amount2 * 946.4) + (amount);
				convertBackTo(unit, d);
			}
			else {
				d = amount - amount2 * 946.4;
				convertBackTo(unit, d);

			}
			return d;
		}
		if (mainUnit == "tbsp") {
			if (del == 'n') {
				d = (amount2 * 14.787) + (amount);
				convertBackTo(unit, d);
			}
			else {
				d = amount - amount2 * 14.787;
				convertBackTo(unit, d);

			}
			return d;
		}
		if (mainUnit == "tsp") {
			if (del == 'n') {
				d = (amount2 * 4.929) + (amount);
				convertBackTo(unit, d);
			}
			else {
				d = amount - amount2 * 4.929;
				convertBackTo(unit, d);

			}
			return d;
		}
		if (mainUnit == "gal") {
			if (del == 'n') {
				d = (amount2 * 3785) + (amount);
				convertBackTo(unit, d);
			}
			else {
				d = amount - amount2 * 3785;
				convertBackTo(unit, d);			}
			return d;
		}

	}



void ingredients::convertBackTo(std::string unit, double& amount) {
	if (unit == "ml" or unit == "") { // Unit conversion table that turns all inputs into cups to be manipulated
		amount = amount;
	}
	else if (unit == "fl oz") {
		amount /= 29.574;
	}
	else if (unit == "c") {
		amount /= 236.6;
	}
	else if (unit == "pt") {
		amount /= 473.2;
	}
	else if (unit == "qt") {
		amount /= 946.4;
	}
	else if (unit == "gal") {
		amount /= 3785;
	}
	else if (unit == "tbsp") {
		amount /= 14.787;
	}
	else if (unit == "tsp") {
		amount /= 4.929;
	}
	else if (unit == "L") {
		amount /= 1000;
	}
	else if (unit == "mg") {
		amount = amount;
	}
	else if (unit == "g") {
		amount /= 1000;
	}
	else if (unit == "kg") {
		amount /= 1000000;
	}
	else if (unit == "oz") {
		amount /= 28350;
	}
	else if (unit == "lb") {
		amount /= 453600;
	}
}



double ingredients::converToG(ingredients ingredient, ingredients newIngredient, char del) {
	std::string unit = ingredient.getUnit();
	double amount = ingredient.getAmount();
	std::string mainUnit = newIngredient.getUnit();
	double amount2 = newIngredient.getAmount(); //common variable
	double d = 0;
	
	if (unit == "mg") {
		amount = amount;
	}
	else if (unit == "g") {
		amount *= 1000;
	}
	else if (unit == "kg") {
		amount *= 1000000;
	}
	else if (unit == "oz") {
		amount *= 28350;
	}
	else if (unit == "lb") {
		amount *= 453600;
	}
	if (del == 'e') {
		convertBackTo(mainUnit, amount);
		return amount;
	}

	if (mainUnit == "mg") {
		if (del == 'n') { // if del == 'n' then the function is being called in terms of adding an ingredient
			d = (amount2) + (amount);
			convertBackTo(unit, d);
		}
		else {
			d = amount - amount2; //otherwise its being called when the amount is being entered back into the vector from cups to the main unit
			convertBackTo(unit, d);

		}
		return d;

	}
	if (mainUnit == "g") {
		if (del == 'n') { // if del == 'n' then the function is being called in terms of adding an ingredient
			d = (amount2*1000)+(amount);
			convertBackTo(unit, d);
		}
		else {
			d = amount - (amount2 * 1000); //otherwise its being called when the amount is being entered back into the vector from cups to the main unit
			convertBackTo(unit, d);

		}
		return d;

	}
	if (mainUnit == "kg") {
		if (del == 'n') { // if del == 'n' then the function is being called in terms of adding an ingredient
			d = (amount2*1000000)+(amount);
			convertBackTo(unit, d);
		}
		else {
			d = amount - (amount2 * 1000000); //otherwise its being called when the amount is being entered back into the vector from cups to the main unit
			convertBackTo(unit, d);

		}
		return d;

	}
	if (mainUnit == "oz") {
		if (del == 'n') { // if del == 'n' then the function is being called in terms of adding an ingredient
			d = (amount2*28350)+(amount);
			convertBackTo(unit, d);
		}
		else {
			d = amount - (amount2 * 28350); //otherwise its being called when the amount is being entered back into the vector from cups to the main unit
			convertBackTo(unit, d);

		}
		return d;

	}
	if (mainUnit == "lb") {
		if (del == 'n') { // if del == 'n' then the function is being called in terms of adding an ingredient
			d = (amount2*453600)+(amount);
			convertBackTo(unit, d);
		}
		else {
			d = amount - (amount2 * 453600); //otherwise its being called when the amount is being entered back into the vector from cups to the main unit
			convertBackTo(unit, d);

		}
		return d;

	}
}

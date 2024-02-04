#pragma once
#include "Ingredients.h"
#include <map>
#include <vector>


ingredients::ingredients() {
    this->amount = 0;
    this->unit = "";
    this->name = "";
}
ingredients::ingredients(double amount, std::string unit, std::string name) {
    this->amount = amount;
    this->unit = unit;
    this->name = name;
}

void ingredients::setAmount(double amount) {
    this->amount = amount;
}
void ingredients::getUnit(std::string unit) {
    this->unit = unit;
}

int ingredients::getChoice() {
    std::vector<std::string> units = { "", "ml", "fl oz", "c", "pt", "qt", "gal", "tbsp", "tsp", "L", "mg", "g", "kg", "oz", "lb" };

    for (int i = 0; i < 17; i++) {
        std::string choice = units[i];
        if (choice  == unit){
            return i;
        }
    }
    return -1;
}






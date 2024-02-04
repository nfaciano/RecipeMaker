#pragma once
#include <string>

class ingredients {
private:
    double amount;
    std::string name;
    std::string unit;
public:
    ingredients();
    ingredients(double amount,std::string unit, std::string name);
    double getAmount() const { return amount; }
    std::string getUnit() const { return unit; }
    std::string getName() const { return name; }
    void setAmount(double amount);
    void getUnit(std::string unit);


    int getChoice();

    double converToC(ingredients ingredient, ingredients newIngredient, char d);
    double converToG(ingredients ingredient, ingredients newIngredient, char d);
    void convertBackTo(std::string unit, double& amount);



};

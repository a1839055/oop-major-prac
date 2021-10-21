#include <string>

using namespace std;

#ifndef INGREDIENT_INFORMATION_H
#define INGREDIENT_INFORMATION_H

// Used to hold information from the ingredients CSV
struct IngredientInformation {
    int id;
    string name;
    float price;
};

#endif
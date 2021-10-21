#include <iostream>
#include <string>

#include "burger.h"
#include "ingredient.h"


using namespace std;

extern string to_string_precision(const float value, const int precision = 2);

Burger::Burger() {
    ingredient_count = 0;
}

Burger::Burger(string n) {
    name = n;
    ingredient_count = 0;
}

Burger::Burger(string n, float p) {
    name = n;
    price = p;
    ingredient_count = 0;
}

Burger::~Burger() {
    
}

vector<Ingredient*> Burger::get_ingredients() {
    return ingredients;
}

void Burger::add_ingredient(Ingredient* ingredient) {
    ingredients.push_back(ingredient);
};

void Burger::remove_ingredient(int index) {
    ingredients.erase(ingredients.begin() + index);
}

float Burger::get_price() {
    // Return the price given by the burger base price and the sum of the ingredient prices
    float p = price;
    for (int i = 0; i < ingredients.size(); i++) {
        p += ingredients.at(i) -> get_price();
    }
    return p;
}

// Display the burger in a human readable format
string Burger::get_display() {
    string display = get_name()+ " - $" + to_string_precision(get_price()) + " - Ingredients: " ;
    for (int i = 0 ; i < ingredients.size(); i++) {
        display += ingredients.at(i) -> get_display();
        if (i != ingredients.size() - 1) display += ", "; // Not the last one
    }
    return display;
}
#include <iostream>
#include <string>

#include "burger.h"
#include "ingredient.h"

using namespace std;

Burger::Burger() {
    ingredient_count = 0;
    ingredients = new Ingredient[0];
}

Burger::Burger(string n) {
    name = n;
    ingredient_count = 0;
    ingredients = new Ingredient[0];
}

Burger::Burger(string n, float p) {
    name = n;
    price = p;
    ingredient_count = 0;
    ingredients = new Ingredient[0];
}

Burger::~Burger() {
    
}

Ingredient* Burger::get_ingredients() {
    return ingredients;
}

void Burger::add_ingredient(Ingredient ingredient) {
    Ingredient* temp = new Ingredient[ingredient_count++];
    for (int i = 0; i < ingredient_count-1; i++) {
        temp[i] = ingredients[i];
    }
    temp[ingredient_count-1] = ingredient;
};

void Burger::remove_ingredient(Ingredient ingredient) {
    Ingredient* temp = new Ingredient[ingredient_count--];
    int count = 0;
    for (int i = 0; i < ingredient_count; i++) {
        // Check if the ingredient matches and an ingredient by that name has not already been removed.
        if (ingredients[i].get_name() != ingredient.get_name() || count+1 != i) {
            ingredients[count++] = ingredients[i];
        }
    }
}

string Burger::get_display() {
    return get_name()+ " - $" + to_string(get_price());
}
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

Burger::Burger(string n, int p) {
    name = n;
    price = p;
    ingredient_count = 0;
    ingredients = new Ingredient[0];
}

Ingredient* Burger::getIngredients() {
    return ingredients;
}

void Burger::addIngredient(Ingredient ingredient) {
    Ingredient* temp = new Ingredient[ingredient_count++];
    for (int i = 0; i < ingredient_count-1; i++) {
        temp[i] = ingredients[i];
    }
    temp[ingredient_count-1] = ingredient;
};

void Burger::removeIngredient(Ingredient ingredient) {
    Ingredient* temp = new Ingredient[ingredient_count--];
    int count = 0;
    for (int i = 0; i < ingredient_count; i++) {
        // Check if the ingredient matches and an ingredient by that name has not already been removed.
        if (ingredients[i].getName() != ingredient.getName() || count+1 != i) {
            ingredients[count++] = ingredients[i];
        }
    }
}

string Burger::getDisplay() {
    return "Name: " + getName()+ " Price: $" + to_string(getPrice());
}

Burger::~Burger() {
    
}
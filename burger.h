#include <string>

#include "item.h"
#include "ingredient.h"

using namespace std;

#ifndef BURGER_H
#define BURGER_H

class Burger: public Item {
    private:
        Ingredient* ingredients;
        int ingredient_count;
    public:
        Burger();
        Burger(string name);
        Burger(string n, int p);

        Ingredient* getIngredients();
        void addIngredient(Ingredient ingredient);
        void removeIngredient(Ingredient ingredient);
        
        string getDisplay();

        ~Burger();
};

#endif
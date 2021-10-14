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
        Burger(string n, float p);

        ~Burger();

        Ingredient* get_ingredients();
        void add_ingredient(Ingredient ingredient);
        void remove_ingredient(Ingredient ingredient);
        
        string get_display();
};

#endif
#include <string>
#include <vector>

#include "item.h"
#include "ingredient.h"

using namespace std;

#ifndef BURGER_H
#define BURGER_H

class Burger: public Item {
    private:
        vector<Ingredient*> ingredients;
        int ingredient_count;
    public:
        Burger();
        Burger(string name);
        Burger(string n, float p);

        ~Burger();

        vector<Ingredient*> get_ingredients();
        void add_ingredient(Ingredient* ingredient);
        void remove_ingredient(int index);

        float get_price();
        
        string get_display();
};

#endif
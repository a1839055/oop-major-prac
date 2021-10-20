#include <string>

#include "item.h"

using namespace std;

#ifndef INGREDIENT_H
#define INGREDIENT_H

class Ingredient: public Item {
    public:
        Ingredient(string name, float price);
};

#endif
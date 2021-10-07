#include <string>

#include "sized_item.h"
#include "ingredient.h"

using namespace std;

#ifndef DRINK_H
#define DRINK_H

class Drink: public SizedItem {
    public:
        Drink(string name, float prices[3]);
};

#endif
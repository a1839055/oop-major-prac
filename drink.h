#include <string>

#include "sized_item.h"
#include "ingredient.h"

using namespace std;

#ifndef DRINK_H
#define DRINK_H

class Drink: public SizedItem {
    public:
        Drink();
        Drink(string name, float prices[3]);

        ~Drink();

        string get_display();
};

#endif
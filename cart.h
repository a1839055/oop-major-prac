#include <vector>

#include "item.h"
#include "burger.h"
#include "drink.h"
#include "fries.h"

#ifndef CART_H
#define CART_H

class Cart {
    private:
        vector<Burger> burgers;
        vector<Drink> drinks;
        vector<Fries> fries;
    public:
        Cart();

        Item* getItems();

        void addBurger(Burger burger);
        void removeBurger(int id);

        void addDrink(Drink drink);
        void removeDrink(Drink drink);

        void addFries(Fries fries);
        void removeFries(Fries fries);
};

#endif
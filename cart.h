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
        
        ~Cart();

        // Item* get_items();

        void add_burger(Burger burger);

        void add_drink(Drink drink);

        void add_fries(Fries fries);

        void remove_item(int index);

        string get_display();
};

#endif
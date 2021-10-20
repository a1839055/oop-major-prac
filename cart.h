#include <vector>

#include "item.h"
#include "burger.h"
#include "drink.h"
#include "fries.h"

#ifndef CART_H
#define CART_H

class Cart {
    private:
        vector<Item*> items;

        vector<Burger*> burgers;
        vector<Drink*> drinks;
        vector<Fries*> fries;

        template <typename T>
        int get_item_index(Item* item_ptr, vector<T*>& items) {
            auto it = find(items.begin(), items.end(), item_ptr);
            if (it != items.end()) {
                return distance(items.begin(), it);
            } else {
                return -1;
            }
    }
    public:
        Cart();
        
        ~Cart();

        void add_burger(Burger* burger);
        void add_drink(Drink* drink);
        void add_fries(Fries* fries);

        void add_burger_ingredient(int index, Ingredient* ingredient);

        void remove_item(int index);

        float get_total();

        string get_display();
};

#endif
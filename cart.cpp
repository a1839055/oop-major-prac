#include <string>
#include <vector>
#include <type_traits>
#include <iostream>
#include <algorithm>

#include "cart.h"
#include "burger.h"
#include "drink.h"
#include "fries.h"
#include "item.h"
#include "ingredient.h"
#include "utils.h"

using namespace std;

extern string to_string_precision(const float value, const int precision = 2);

Cart::Cart() {
    
}

Cart::~Cart() {
    // Only need to deallocate items as it contains all the pointers in the other arrays combined
    deallocate_pointer_vector<Item*>(items);
}

void Cart::add_burger(Burger* burger) {
    items.push_back(burger);
    burgers.push_back(burger);   
}

void Cart::add_drink(Drink* drink) {
    items.push_back(drink);
    drinks.push_back(drink);
}

void Cart::add_fries(Fries* f) {
    items.push_back(f);
    fries.push_back(f);
}

void Cart::add_burger_ingredient(int index, Ingredient* ingredient) {
    index--;
    Burger* burger = burgers.at(get_item_index(items.at(index), burgers));
    burger -> add_ingredient(ingredient);
    cout << burger -> get_price() << endl;
}

void Cart::remove_item(int index) {
    index--;

    Item* item = items.at(index);
    items.erase(items.begin()+index);

    int burger_index = get_item_index(item, burgers);
    if (burger_index > 0) {
        burgers.erase(burgers.begin()+burger_index);
    }
    int drinks_index = get_item_index(item, drinks);
    if (drinks_index > 0) {
        drinks.erase(drinks.begin()+drinks_index);
    } 
    int fries_index = get_item_index(item, fries);
    if (fries_index > 0) {
        fries.erase(fries.begin()+fries_index);
    }
}

float Cart::get_total() {
    float sum = 0;
    for (int i = 0; i < items.size(); i++) {
        sum += items[i]->get_price();
    }
    return sum;
}

string Cart::get_display() {
    string display = "";

    display += "Total: " + to_string_precision(get_total()) + "\n";

    for (int i = 0; i < items.size(); i++) {
        Item* item = items.at(i);
        display += "\n\t" + to_string(i+1) + ". " + item->get_display();
    }
    
    return display;
}
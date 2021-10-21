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

// Add a burger to the cart
void Cart::add_burger(Burger* burger) {
    items.push_back(burger);
    burgers.push_back(burger);   
}

// Add a drink to the cart
void Cart::add_drink(Drink* drink) {
    items.push_back(drink);
    drinks.push_back(drink);
}

// Add fries to the cart
void Cart::add_fries(Fries* f) {
    items.push_back(f);
    fries.push_back(f);
}

// Find the burger with the given index in the cart and then add the ingredient to it
void Cart::add_burger_ingredient(int index, Ingredient* ingredient) {
    index--;
    Burger* burger = burgers.at(get_item_index(items.at(index), burgers));
    burger -> add_ingredient(ingredient);
    cout << burger -> get_price() << endl;
}

// Remove the item with the given index from the cart
void Cart::remove_item(int index) {
    index--;

    // Remove from items array
    Item* item = items.at(index);
    items.erase(items.begin()+index);

    // Find which of the specific vectors it is in and remove it
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
    // Sum the price from all items
    float sum = 0;
    for (int i = 0; i < items.size(); i++) {
        sum += items[i]->get_price();
    }
    return sum;
}

// Return a string that displays cart information in a human readable format
string Cart::get_display() {
    string display = "";

    display += "Total: " + to_string_precision(get_total()) + "\n";

    for (int i = 0; i < items.size(); i++) {
        Item* item = items.at(i);
        display += "\n\t" + to_string(i+1) + ". " + item->get_display();
    }
    
    return display;
}
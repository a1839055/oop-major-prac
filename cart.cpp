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

using namespace std;

Cart::Cart() {
    
}

Cart::~Cart() {

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

string Cart::get_display() {
    string display = "";

    for (int i = 0; i < items.size(); i++) {
        Item* item = items.at(i);
        display += "\n\t" + to_string(i+1) + ". " + item->get_display();
    }
    
    return display;
}
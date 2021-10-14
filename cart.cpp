#include <string> 

#include "cart.h"
#include "burger.h"
#include "drink.h"
#include "fries.h"

using namespace std;

Cart::Cart() {
    
}

Cart::~Cart() {

}

void Cart::add_burger(Burger burger) {
    burgers.push_back(burger);   
}

void Cart::add_drink(Drink drink) {
    drinks.push_back(drink);
}

void Cart::add_fries(Fries f) {
    fries.push_back(f);
}

void Cart::remove_item(int index) {
    if (index >= burgers.size()) {
        index -= burgers.size();
        if (index >= drinks.size()) {
            index -= drinks.size();
            if (index >= fries.size()) {
                // Index is too large
                throw;
            } else {
                fries.erase(fries.begin()+index);
            }
        } else {
            drinks.erase(drinks.begin()+index);
        }
    } else {
        burgers.erase(burgers.begin()+index);
    }
}

string Cart::get_display() {
    string data = "Burgers:\n";
    for (int i = 0; i < burgers.size(); i++) {
        data += to_string(i+1) + "." + burgers[i].get_display() + "\n";
    }

    data += "Drinks:\n";
    for (int i = 0; i < drinks.size(); i++) {
        data += "\t" + to_string(burgers.size()+i+1) + "." + drinks[i].get_display() + "\n";
    }

    data += "Fries:\n";
    for (int i = 0; i < fries.size(); i++) {
        data += "\t" + to_string(burgers.size()+drinks.size()+i+1) + "." + fries[i].get_display() + "\n";
    }

    return data;
}

// Item* get_items() {
//     return burgers;
// }
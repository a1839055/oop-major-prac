#include "cart.h"
#include "burger.h"
#include "drink.h"
#include "fries.h"

Cart::Cart() {
    
}

void Cart::addBurger(Burger burger) {
    burgers.push_back(burger);   
}

void Cart::removeBurger(Burger burger) {
    for (int i = 0; i < burgers.size(); i++) {
        if (burgers[i] == burger) {
            burgers.erase(burgers.begin()+i);
            break;
        }
    }
}
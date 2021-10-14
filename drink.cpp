#include <string>

#include "drink.h"

using namespace std;

Drink::Drink() {
    name = "";
    prices = new float[3];
    prices_count = 3;
    size = 0;
}

Drink::Drink(string n, float p[3]) {
    name = n;
    prices = p;
    prices_count = 3;
    size = 0;
}

Drink::~Drink() {
    
}

string Drink::get_display() {
    return "";
}
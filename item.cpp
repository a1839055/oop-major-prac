#include <string>

#include "item.h"

using namespace std;

string Item::getName() {
    return name;
}

void Item::setName(string n) {
    name = n;
}

float Item::getPrice() {
    return price;
}

void Item::setPrice(float p) {
    price = p;
}

string Item::getDisplay() {
    return "Name: " + getName() + " Price: " + to_string(getPrice());
}
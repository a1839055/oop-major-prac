#include <string>

#include "item.h"

using namespace std;

string Item::get_name() {
    return name;
}

void Item::setName(string n) {
    name = n;
}

float Item::get_price() {
    return price;
}

void Item::setPrice(float p) {
    price = p;
}

string Item::get_display() {
    return "Name: " + get_name() + " Price: " + to_string(get_price());
}

bool Item::operator==(const Item other) const {
    return name == other.name;
}
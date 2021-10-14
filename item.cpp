#include <string>

#include "item.h"

using namespace std;

Item::Item() {

}

Item::~Item() {

}

string Item::get_name() {
    return name;
}

void Item::set_name(string n) {
    name = n;
}

float Item::get_price() {
    return price;
}

void Item::set_price(float p) {
    price = p;
}

string Item::get_display() {
    return get_name() + " - $" + to_string(get_price());
}

bool Item::operator==(const Item other) const {
    return name == other.name;
}
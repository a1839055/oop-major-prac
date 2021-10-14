#include "sized_item.h"

SizedItem::SizedItem() {

}

SizedItem::~SizedItem() {

}

int SizedItem::set_size() {
    return size;
}

void SizedItem::set_size(int s) {
    if (s >= 0 && s <= prices_count) {
        size = s;
    }
}

float* SizedItem::get_prices() {
    return prices;
}

void SizedItem::set_prices(float* p) {
    prices = p;
}

float SizedItem::get_price() {
    return get_prices()[set_size()];
}

string SizedItem::get_display() {
    return "Name: " + get_name() + " Price: $" + to_string(get_price());
}
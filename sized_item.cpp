#include "sized_item.h"


extern string to_string_precision(const float value, const int precision = 2);

SizedItem::SizedItem() {

}

SizedItem::~SizedItem() {
    delete[] prices;
}

int SizedItem::set_size() {
    return size;
}

void SizedItem::set_size(int s) {
    if (s >= 0 && s <= prices_count) {
        size = s;
    }
}

string SizedItem::get_size_display() {
    switch (size) {
        case 0:
            return "small";
        case 1:
            return "medium";
        default: // 2 or more is large
            return "large";
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
    return get_name() + " - $" + to_string_precision(get_price()) + " (" + get_size_display() + ")";
}
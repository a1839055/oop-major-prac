#include "sized_item.h"

int SizedItem::getSize() {
    return size;
}

void SizedItem::setSize(int s) {
    if (s >= 0 && s <= prices_count) {
        size = s;
    }
}

float* SizedItem::getPrices() {
    return prices;
}

void SizedItem::setPrices(float* p) {
    prices = p;
}

float SizedItem::getPrice() {
    return getPrices()[getSize()];
}
#include <string>
#include <iostream>
#include <map>

#include "fries.h"
#include "burger.h"
#include "drink.h"
#include "item.h"

using namespace std;

extern map<string, float> getItemPricing();

int main() {
    // Populate this from menu file
    map<string, float> itemPricing = getItemPricing();

    cout << "Welcome to McDonald's!" << endl << endl;
    cout << "Pricing:" << endl;
    for (auto const& [item, price]: itemPricing) {
        cout << "\t" << item << ": $" << price << endl;
    }

    int cart_count = 0;
    Item* cart = new Item[0];

    return 0;
}
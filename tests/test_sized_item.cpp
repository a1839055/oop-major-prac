#include <iostream>

#include "../sized_item.h"

using namespace std;

int main() {
    SizedItem* sized_item = new SizedItem();
    float prices[2] = {1, 2};
    sized_item->set_prices(prices, 2);
    sized_item->set_name("Cheese");

    cout << "Sized_item: " << sized_item->get_display() << endl;

    sized_item->set_name("Pepper");

    cout << "Sized_item: " << sized_item->get_display() << endl;
}
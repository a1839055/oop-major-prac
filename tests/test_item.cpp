#include <iostream>

#include "../item.h"

using namespace std;

int main() {
    Item* item = new Item();
    item->set_name("Cheeseitem");
    item->set_price(4.35);

    cout << "Item: " << item->get_display() << endl;

    item->set_name("Pepper");

    cout << "Item: " << item->get_display() << endl;
}
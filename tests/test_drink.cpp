#include <iostream>

#include "../drink.h"

using namespace std;

int main() {
    float prices[3] = {3.5, 3.75, 4};
    Drink drink = Drink("Vanilla Coke", prices);
    cout << "Drink: " << drink.get_display() << endl;

    drink.setSize(1);
    cout << "Drink: " << drink.get_display() << endl;
;}
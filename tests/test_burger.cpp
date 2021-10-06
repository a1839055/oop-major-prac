#include <iostream>

#include "../burger.h"

using namespace std;

int main() {
    Burger burger = Burger();
    burger.setName("Cheeseburger");
    burger.setPrice(4.35);
    cout << "Burger: " << burger.getDisplay() << endl;

    burger = Burger("Quarter Pounder");
    burger.setPrice(5.00);
    cout << "Burger: " << burger.getDisplay() << endl;

    burger = Burger("Big Mac", 5.00);
    burger.setPrice(6.00);
    cout << "Burger: " << burger.getDisplay() << endl;
;}
#include <iostream>

#include "../burger.h"
#include "../ingredient.h"

using namespace std;

int main() {
    Burger burger = Burger();
    burger.set_name("Cheeseburger");
    burger.set_price(4.35);
    cout << "Burger: " << burger.get_display() << endl;

    burger = Burger("Quarter Pounder");
    burger.set_price(5.00);
    cout << "Burger: " << burger.get_display() << endl;

    burger = Burger("Big Mac", 5.00);
    burger.set_price(6.00);

    Ingredient ingredient = Ingredient("Cheese", 0.5);
    burger.add_ingredient(&ingredient);

    cout << "Burger: " << burger.get_display() << endl;
}
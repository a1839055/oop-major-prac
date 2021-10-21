#include <iostream>

#include "../ingredient.h"

using namespace std;

int main() {
    Ingredient* ingredient = new Ingredient("Cheese", 0.5);
    ingredient->set_price(4.35);

    cout << "Ingredient: " << ingredient->get_display() << endl;

    ingredient->set_name("Pepper");

    cout << "Ingredient: " << ingredient->get_display() << endl;
}
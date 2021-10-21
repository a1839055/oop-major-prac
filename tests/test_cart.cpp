#include <iostream>

#include "../cart.h"
#include "../burger.h"
#include "../fries.h"
#include "../drink.h"
#include "../ingredient.h"

using namespace std;

int main() {
    Cart cart = Cart();
    cout << cart.get_display() << endl;

    Burger* burger = new Burger("Cheeseburger", 3.5);
    cart.add_burger(burger);

    Ingredient* ingredient = new Ingredient("Cheese", 0.5);
    burger->add_ingredient(ingredient);

    cart.add_burger_ingredient(1, ingredient);
    
    // Should show two cheeses
    cout << cart.get_display() << endl;

    float drink_prices[3] = {3.5, 4.5, 5};
    Drink* drink = new Drink("Coke", drink_prices);
    cart.add_drink(drink);
    
    float fries_prices[2] = {3.5, 4.5};
    Fries* fries = new Fries("Fries", fries_prices, 2);
    cart.add_fries(fries);

    cout << cart.get_display() << endl;

    cart.remove_item(1);

    // Should show just the drink and fries
    cout << cart.get_display() << endl;
}
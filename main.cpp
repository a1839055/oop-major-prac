#include <string>
#include <iostream>
#include <map>

#include "fries.h"
#include "burger.h"
#include "drink.h"
#include "item.h"
#include "cart.h"
#include "ingredient.h"
#include "burger_information.h"
#include "drink_information.h"
#include "fries_information.h"
#include "ingredient_information.h"

using namespace std;

#define FIXED_FLOAT(x) std::fixed <<std::setprecision(2)<<(x)

// extern map<string, float> getItemPricing();
extern map<int, BurgerInformation> get_burgers_info();
extern map<int, IngredientInformation> get_ingredients_info();
extern map<int, DrinkInformation> get_drinks_info();
extern map<int, FriesInformation> get_fries_info();
extern string get_menu_display();

int main() {
    // Populate this from menu file
    map<int, BurgerInformation> burgers_info = get_burgers_info();
    map<int, IngredientInformation> ingredients_info = get_ingredients_info();
    map<int, DrinkInformation> drinks_info = get_drinks_info();
    map<int, FriesInformation> fries_info = get_fries_info();

    Cart cart = Cart();

    cout << "Welcome to McDonald's!" << endl << endl;

    cout << "Commands: " << endl;
    cout << "\tburger <id> - Adds a burger to the cart." << endl;
    cout << "\tdrink <id> <size> - Adds a drink with the given size to the cart." << endl;
    cout << endl;
    cout << "\tremove <number> - Removes the item with the given number from the cart" << endl;

    cout << endl;

    cout << "Pricing:" << endl << get_menu_display() << endl;

    cout << endl;

    string input;
    cout << "Enter command: ";
    while (cin >> input && input != "quit") {
        if (input == "quit") {
            break;
        }
        if (input == "burger") {
            int id;
            cin >> id;

            Burger* burger = new Burger(burgers_info[id].name, burgers_info[id].price);
            cart.add_burger(burger);
        } else if (input == "drink") {
            int id;
            cin >> id;

            int size;
            cin >> size;

            Drink* drink = new Drink(drinks_info[id].name, drinks_info[id].prices, size);
            cart.add_drink(drink);
        } else if (input == "fries") {
            int id;
            cin >> id;

            int size;
            cin >> size;

            Fries* fries = new Fries(fries_info[id].name, fries_info[id].prices, 3, size);
            cart.add_fries(fries);
        } else if (input == "remove" ) {
            int id;
            cin >> id;

            cart.remove_item(id);
        } else if (input == "ingredient") {
            int index;
            cin >> index;

            int ingredient_id;
            cin >> ingredient_id;

            Ingredient* ingredient = new Ingredient(ingredients_info[ingredient_id].name, ingredients_info[ingredient_id].price);
            cart.add_burger_ingredient(index, ingredient);
        } else if (input == "menu") {
            cout << "Pricing:" << endl << get_menu_display() << endl;
        } else if (input == "pay") {
            string method;
            cin >> method;

            if (method == "paypal") {

            } else if (method == "cc") {

            } else if (method == "cash") {
            
            } else {
                cout << "Unrecognized payment method";
            }
        } else {
            cout << "Unknown command." << endl;
        }

        cout << endl << "Current Cart: " << endl << cart.get_display() << endl << endl;

        cout << "Enter command: ";
    }

    return 0;
}
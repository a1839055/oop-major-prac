#include <string>
#include <iostream>
#include <map>

#include "fries.h"
#include "burger.h"
#include "drink.h"
#include "item.h"
#include "cart.h"
#include "burger_information.h"
#include "drink_information.h"
#include "fries_information.h"

using namespace std;

// extern map<string, float> getItemPricing();
extern map<int, BurgerInformation> get_burgers_info();
extern map<int, DrinkInformation> get_drinks_info();
extern map<int, FriesInformation> get_fries_info();
extern string get_menu_display();

int main() {
    // Populate this from menu file
    map<int, BurgerInformation> burgers_info = get_burgers_info();
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
    // cout << "\tBurger:" << endl;
    // for (auto const& [name, information]: burgers_info) {
    //     cout << "\t\t" << information.id << ". " << information.name << ": $" << information.price << endl;
    // }

    // cout << "\tDrinks:" <<endl;
    // for (auto const& [name, information]: drinks_info) {
    //     cout << "\t\t" << information.id << ". " << information.name << ": $" << information.prices[0] << ", $" << information.prices[1] << ", $" << information.prices[2] <<endl;
    // }

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

            Fries* fries = new Fries(fries_info[id].name, fries_info[id].prices, size);
            cart.add_fries(fries);
        } else if (input == "remove" ) {
            int id;
            cin >> id;

            cart.remove_item(id);
        } else if (input == "menu") {
            cout << "Pricing:" << endl << get_menu_display() << endl;
        } else {
            cout << "Unknown command." << endl;
        }

        cout << endl << "Current Cart: " << endl << cart.get_display() << endl << endl;

        cout << "Enter command: ";
    }

    return 0;
}
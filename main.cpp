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

using namespace std;

// extern map<string, float> getItemPricing();
extern map<int, BurgerInformation> get_burgers_info();
extern map<int, DrinkInformation> get_drinks_info();

int main() {
    // Populate this from menu file
    map<int, BurgerInformation> burgers_info = get_burgers_info();
    map<int, DrinkInformation> drinks_info = get_drinks_info();

    Cart cart = Cart();

    cout << "Welcome to McDonald's!" << endl << endl;
    cout << "Pricing:" << endl;
    cout << "\tBurger:" << endl;
    for (auto const& [name, information]: burgers_info) {
        cout << "\t\t" << information.id << ". " << information.name << ": $" << information.price << endl;
    }

    string input;
    cout << "Enter command: ";
    while (cin >> input && input != "quit") {
        if (input == "quit") {
            break;
        }
        if (input == "burger") {
            int id;
            cin >> id;
            cout << "You are ordering a burger with id " << id << endl;
            Burger burger = Burger(burgers_info[id].name, burgers_info[id].price);
            cart.add_burger(burger);
        } else if (input == "remove" ) {
            int id;
            cin >> id;
            cart.remove_item(id);
        } else {
            cout << "Unknown command." << endl;
        }

        cout << "Current Cart: " << cart.get_display() << endl;

        cout << "Enter command: ";
    }

    return 0;
}
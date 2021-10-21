#include <string>
#include <iostream>
#include <map>
#include <random>


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
#include "payment_system.h"

using namespace std;

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

    // Create empty cart
    Cart cart = Cart();

    // Print out all the instructions
    cout << "Welcome to McDonald's!" << endl << endl;

    cout << "Commands: " << endl;
    cout << "\tburger <id> - Adds a burger to the cart." << endl;
    cout << "\tdrink <id> <size> - Adds a drink with the given size to the cart." << endl;
    cout << "\tfries <id> <size> - Adds a fries with the given size to the cart." << endl;
    cout << "\tingredient <burger_id> <ingredient_id> - Adds the ingredient with the given id to the given burger already in the cart." << endl;
    cout << endl;
    cout << "\tremove <number> - Removes the item with the given number from the cart" << endl;

    cout << endl;

    cout << "Note: size is given as a number (0 = small, 1 = medium, 2 = large)." << endl;

    cout << endl;

    // Output menu pricing which was loaded from CSV
    cout << "Pricing:" << endl << get_menu_display() << endl;

    cout << endl;

    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> distr(0, 99); // define the range

    string first_name;
    cout << "Please enter your first name: ";
    cin >> first_name;

    int order_id = distr(gen);

    // Read in the first part of the command (the command name)
    string input;
    cout << "Enter command: ";
    while (cin >> input && input != "quit") {
        try {
            bool show_cart = true;
            // Check what command has been called
            if (input == "quit") {
                string confirm;
                cout << "Are you sure you wish to quit? (y/n)";
                cin >> confirm;
                if (confirm[0] == 'y') {
                    break;
                } else {
                    show_cart = false;
                }
            }
            if (input == "burger") {
                // Read in the id
                int id;
                cin >> id;

                // Create burger and add it to the cart
                Burger* burger = new Burger(burgers_info[id].name, burgers_info[id].price);
                cart.add_burger(burger);
            } else if (input == "drink") {
                // Read in id and size 
                int id;
                cin >> id;

                int size;
                cin >> size;

                // Creat drink and add it to the cart 
                Drink* drink = new Drink(drinks_info[id].name, drinks_info[id].prices, size);
                cart.add_drink(drink);
            } else if (input == "fries") {
                // Read in id and size of the fries
                int id;
                cin >> id;

                int size;
                cin >> size;

                Fries* fries = new Fries(fries_info[id].name, fries_info[id].prices, 3, size);
                cart.add_fries(fries);
            } else if (input == "remove" ) {
                // Read in the index in the cart of the item to remove
                int index;
                cin >> index;

                // Remove the item at the given index
                cart.remove_item(index);
            } else if (input == "ingredient") {
                // Read in the index of the burger and the id of the ingredient to be added
                int index;
                cin >> index;

                int ingredient_id;
                cin >> ingredient_id;

                // Create and add the ingredient to the burger already in the cart
                Ingredient* ingredient = new Ingredient(ingredients_info[ingredient_id].name, ingredients_info[ingredient_id].price);
                cart.add_burger_ingredient(index, ingredient);
            } else if (input == "menu") {
                cout << "Pricing:" << endl << get_menu_display() << endl;
                show_cart = false;
            } else if (input == "pay") {
                show_cart = false;

                string method;
                cin >> method;

                // Create generic payment object
                Payment* payment;
                bool success = true;

                if (method == "paypal") {
                    // Instantiate paypal object and assign to payment
                    Paypal* paypal = new Paypal(cart.get_total(), first_name, order_id, 100+order_id, first_name);
                    payment = paypal;
                } else if (method == "cc") {
                    CreditCard* credit_card = new CreditCard(cart.get_total(), first_name, order_id, 100+order_id, first_name);
                    payment = credit_card;
                } else if (method == "cash") {
                    Cash* cash = new Cash(cart.get_total(), first_name, order_id, 100+order_id, first_name);
                    payment = cash;
                } else {
                    cout << "Unrecognized payment method.";
                    success = false;
                }

                // Only proceed if a payment method was succesfully selected
                if (success) {
                    // Use virtual payment method (uses implementation from child class)
                    success = payment->pay();
                    if (success) {
                        cout << "Thank you for choosing Maccas!" << endl;
                        break;
                    }
                }
            } else {
                cout << "Unknown command." << endl;
            }

            if (show_cart) {
                cout << endl << "Current Cart: " << endl << cart.get_display() << endl << endl;
            }
        } catch (const exception& e) {
            cout << "Please try again." << endl;
        }

        cout << "Enter command: ";
    }

    return 0;
}
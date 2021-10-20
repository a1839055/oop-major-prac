#include <string>
#include <map>

#include "csv.h"
#include "burger_information.h"
#include "drink_information.h"
#include "fries_information.h"
#include "ingredient_information.h"


using namespace std;

extern string to_string_precision(const float value, const int precision = 2);

map<int, BurgerInformation> get_burgers_info() {
    map<int, BurgerInformation> info;

    io::CSVReader<2> in("assets/burgers.csv");
    in.read_header(io::ignore_extra_column, "name", "price");
    
    int id = 0;
    string name; float price;
    while(in.read_row(name, price)){
        BurgerInformation burger_information = {++id, name, price};
        info.insert(pair<int, BurgerInformation>(id, burger_information));
    }

    return info;
}

map<int, DrinkInformation> get_drinks_info() {
    map<int, DrinkInformation> info;

    io::CSVReader<4> in("assets/drinks.csv");
    in.read_header(io::ignore_extra_column, "name", "small_price", "medium_price", "large_price");

    int id = 0;
    string name; float small_price, medium_price, large_price;
    while(in.read_row(name, small_price, medium_price, large_price)) {
        float* prices = new float[3]{small_price, medium_price, large_price};
        DrinkInformation drink_information = {++id, name, prices, 3};
        info.insert(pair<int, DrinkInformation>(id, drink_information));
    }

    return info;
}

map<int, FriesInformation> get_fries_info() {
    map<int, FriesInformation> info;

    io::CSVReader<4> in("assets/fries.csv");
    in.read_header(io::ignore_extra_column, "name", "small_price", "medium_price", "large_price");

    int id = 0;
    string name; float small_price, medium_price, large_price;
    while(in.read_row(name, small_price, medium_price, large_price)) {
        float* prices = new float[3]{small_price, medium_price, large_price};
        FriesInformation fries_information = {++id, name, prices, 3};
        info.insert(pair<int, FriesInformation>(id, fries_information));
    }

    return info;
}

map<int, IngredientInformation> get_ingredients_info() {
    map<int, IngredientInformation> info;

    io::CSVReader<2> in("assets/ingredients.csv");
    in.read_header(io::ignore_extra_column, "name", "price");
    
    int id = 0;
    string name; float price;
    while(in.read_row(name, price)){
        IngredientInformation ingredient_information = {++id, name, price};
        info.insert(pair<int, IngredientInformation>(id, ingredient_information));
    }

    return info;
}

string get_menu_display() {
    map<int, BurgerInformation> burgers_info = get_burgers_info();
    map<int, IngredientInformation> ingredients_info = get_ingredients_info();
    map<int, DrinkInformation> drinks_info = get_drinks_info();
    map<int, FriesInformation> fries_info = get_fries_info();

    string display = "";

    display += "\tBurgers:\n";
    for (auto const& [name, information]: burgers_info) {
        display +=  "\t\t" + to_string(information.id) + ". " + information.name + ": $" + to_string_precision(information.price) + "\n";
    }

    display += "\n\t\tIngredients:\n";
    for (auto const& [name, information]: ingredients_info) {
        display +=  "\t\t\t" + to_string(information.id) + ". " + information.name + ": $" + to_string_precision(information.price) + "\n";
    }

    display += "\tDrinks:\n";
    for (auto const& [name, information]: drinks_info) {
        display += "\t\t" + to_string(information.id) + ". " + information.name + ": $" + to_string_precision(information.prices[0]) + ", $" + to_string_precision(information.prices[1]) + ", $" + to_string_precision(information.prices[2]) + "\n";
    }

    display += "\tFries:\n";
    for (auto const& [name, information]: fries_info) {
        display += "\t\t" + to_string(information.id) + ". " + information.name + ": $" + to_string_precision(information.prices[0]) + ", $" + to_string_precision(information.prices[1]) + ", $" + to_string_precision(information.prices[2]) + "\n";
    }

    return display;
}
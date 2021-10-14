#include <string>
#include <map>

#include "csv.h"
#include "burger_information.h"
#include "drink_information.h"

using namespace std;

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
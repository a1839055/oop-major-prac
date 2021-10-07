#include <string>
#include <map>

#include "csv.h"

using namespace std;

map<string, float> getItemPricing() {
    map<string, float> itemPricing;

    io::CSVReader<2> in("assets/menu.csv");
    in.read_header(io::ignore_extra_column, "item", "price");
    string item; float price;
    while(in.read_row(item, price)){
        itemPricing.insert(pair<string, float>(item, price));
    }

    return itemPricing;
}
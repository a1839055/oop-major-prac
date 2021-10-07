#include <string>

#include "drink.h"

using namespace std;

Drink::Drink(string n, float p[3]) {
    name = n;
    prices = p;
    prices_count = 3;
    size = 0;
}
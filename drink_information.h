#include <string>

using namespace std;

#ifndef DRINK_INFORMATION_H
#define DRINK_INFORMATION_H

struct DrinkInformation {
    int id;
    string name;
    float* prices;
    int prices_count;
};

#endif
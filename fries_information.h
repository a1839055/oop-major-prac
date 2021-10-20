#include <string>

using namespace std;

#ifndef FRIES_INFORMATION_H
#define FRIES_INFORMATION_H

struct FriesInformation {
    int id;
    string name;
    float* prices;
    int prices_count;
};

#endif
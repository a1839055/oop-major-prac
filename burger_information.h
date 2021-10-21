#include <string>

using namespace std;

#ifndef BURGER_INFORMATION_H
#define BURGER_INFORMATION_H

// Used to hold information from the burgers CSV
struct BurgerInformation {
    int id;
    string name;
    float price;
};

#endif
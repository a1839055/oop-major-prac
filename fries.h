#include "sized_item.h"

using namespace std;

#ifndef FRIES_H
#define FRIES_H

class Fries: public SizedItem {
    public:
        Fries();
        Fries(float prices[3]);
        Fries(string name, float* prices, int prices_count);

        ~Fries();
};

#endif
#include "sized_item.h"

#ifndef FRIES_H
#define FRIES_H

class Fries: public SizedItem {
    public:
        Fries(float prices[3]);

        string getDisplay();
};

#endif
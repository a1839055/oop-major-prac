#include "item.h"

#ifndef SIZED_ITEM_H
#define SIZED_ITEM_H

class SizedItem : public Item {
    protected:
        int size;
        float* prices;
        int prices_count;
    public:
        int getSize();
        void setSize(int size);
        
        float* getPrices();
        void setPrices(float* prices);

        float getPrice();
        
        string getDisplay();
};

#endif
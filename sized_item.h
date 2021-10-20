#include "item.h"


#ifndef SIZED_ITEM_H
#define SIZED_ITEM_H

class SizedItem : public Item {
    protected:
        int size;
        float* prices;
        int prices_count;
    public:
        SizedItem();
        ~SizedItem();

        int set_size();
        void set_size(int size);
        string get_size_display();
        
        float* get_prices();
        void set_prices(float* prices);

        float get_price();
        
        string get_display();
};

#endif
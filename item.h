#include <string>

using namespace std;

#ifndef ITEM_H
#define ITEM_H

class Item {
    protected:
        string name;
        float price;
    public:
        string get_name();
        void setName(string name);

        float get_price();
        void setPrice(float price);

        virtual string get_display();
};

#endif
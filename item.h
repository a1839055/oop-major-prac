#include <string>

using namespace std;

#ifndef ITEM_H
#define ITEM_H

class Item {
    protected:
        string name;
        float price;
    public:
        string getName();
        void setName(string name);

        float getPrice();
        void setPrice(float price);

        virtual string getDisplay();
};

#endif
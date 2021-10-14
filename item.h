#include <string>

using namespace std;

#ifndef ITEM_H
#define ITEM_H

class Item {
    protected:
        string name;
        float price;
    public:
        Item();
        ~Item();

        string get_name();
        void set_name(string name);

        virtual float get_price();
        virtual void set_price(float price);

        virtual string get_display();

        bool operator==(const Item other) const;
};

#endif
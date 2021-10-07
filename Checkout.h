#ifndef CHECKOUT_H

#define CHECKOUT_H

#include <iostream>

#include <string>

using namespace std;

class checkout {
    public:
        checkout();
        string checkout_options();
        string order_details();
        int price();
        void set_option();
        int get_option();
        ~checkout();
};

class dinein : public checkout {
    public:
        dinein();
        string name();
        int table_number();
        void set_table_number();
        int get_table_number();
        ~dinein();
};

class takeout : public checkout {
    public:
        takeout();
        string name();
        string package_type();
        void set_packageType();
        string get_packageType();
        ~takeout();
};

#endif
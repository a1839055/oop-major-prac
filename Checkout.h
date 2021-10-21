#ifndef CHECKOUT_H

#define CHECKOUT_H

#include <iostream>

#include <string>

using namespace std;

class checkout {
    public:
        checkout(); 
        void checkout_options(int selection); // select which option
        string get_option(); // output option
        int costs(); // price to be connected with order system
        ~checkout(); 
    private:
        string selected_option;
        int button;
};

class dinein : public checkout {
    public:
        dinein();
        void set_table_number(int table); // set table number
        int get_table_number(); // output table number
        ~dinein();
    private:
        int number;
};

class takeout : public checkout {
    public:
        takeout();
        void set_packageType(int Type); // select which package option
        string get_packageType(); // output package option
        ~takeout();
    private:
        int package;
        string optionSelected;
};

#endif
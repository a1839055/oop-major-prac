#ifndef CHECKOUT_H

#define CHECKOUT_H

#include <iostream>

#include <string>

using namespace std;

class checkout {
    public:
        checkout();
        void checkout_options(int selection);
        string get_option();
        int costs();
        ~checkout();
    private:
        string options;
        string selected_option;
        int button;
};

class dinein : public checkout {
    public:
        dinein();
        void set_table_number(int table);
        int get_table_number();
        ~dinein();
    private:
        int number;
};

class takeout : public checkout {
    public:
        takeout();
        void set_packageType(int Type);
        string get_packageType();
        ~takeout();
    private:
        int package;
        string optionSelected;
};

#endif
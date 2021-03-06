#include <iostream>
#include <string>

#include "Checkout.h"

using namespace std;

// CHECKOUT

checkout::checkout() {
    selected_option = " ";
    button = 0;
}

void checkout::checkout_options(int selection) {

    button = selection;

    if(button == 1) { // if statement on which option selected
        selected_option = "Dine-in selected";
    } else if(button == 2) {
        selected_option = "Takeaway selected";
    }
}

string checkout::get_option() {
    return selected_option;
}

int checkout::costs() {
    return 0; // for price to be integrated with other components
}

checkout::~checkout() {

}

// DINE IN

dinein::dinein() {
    number = 0;
}

void dinein::set_table_number(int table) {
    number = table; // initialise
}

int dinein::get_table_number() {
    return number;
}

dinein::~dinein() {

}

// TAKEOUT

takeout::takeout() {
    package = 0;
    optionSelected = " ";
}

void takeout::set_packageType(int Type) {
    package = Type;

    if(package == 1) { // if statement on which package type to be selected
        optionSelected = "Regular";
    } else if(package == 2) {
        optionSelected = "Premium";
    }
}

string takeout::get_packageType() {
    return optionSelected;
}

takeout::~takeout() {
    
}
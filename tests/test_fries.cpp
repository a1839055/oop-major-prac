#include <iostream>

#include "../fries.h"

using namespace std;

int main() {
    float prices[3] = {3.5, 3.75, 4};
    Fries* fries = new Fries(prices);
    cout << "Fries: " << fries->get_display() << endl;

    fries->set_size(1);
    cout << "Fries: " << fries->get_display() << endl;

    float* loaded_fries_prices = new float[2];
    loaded_fries_prices[0] = 3.75;
    loaded_fries_prices[1] = 4.50; 
    Fries* loadedFries = new Fries("Loaded Fries", loaded_fries_prices, 2);
    cout << "Fries: " << loadedFries->get_display() << endl;

    return 0;
}
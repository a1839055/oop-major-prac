#include <iostream>

#include "../fries.h"

using namespace std;

int main() {
    float prices[3] = {3.5, 3.75, 4};
    Fries fries = Fries(prices);
    cout << "Fries: " << fries.getDisplay() << endl;

    fries.setSize(1);
    cout << "Fries: " << fries.getDisplay() << endl;

    float* loadedFriesPrices = new float[2];
    loadedFriesPrices[0] = 3.75;
    loadedFriesPrices[1] = 4.50; 
    Fries loadedFries = Fries("Loaded Fries", loadedFriesPrices, 2);
    cout << "Fries: " << loadedFries.getDisplay() << endl;
;}
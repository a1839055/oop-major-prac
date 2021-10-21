#include <iostream>
#include <string>

#include "Checkout.h"

using namespace std;

int main() {
    checkout test1;

    int number;
    cout << "Select Checkout option: " << endl;
    cout << "For Dine-in, enter 1 " << endl;
    cout << "For Take-out, enter 2 " << endl;
    cin >> number;

    test1.checkout_options(number);

    cout << "Checkout option: " << test1.get_option() << endl;

    if (number == 1) {

        int tableNumber;

        cout << "\nFor Dine-in option" << endl;
        cout << "Enter table number: ";
        cin >> tableNumber;

        dinein check1;
        check1.set_table_number(tableNumber);

        cout << "Table number: " << check1.get_table_number() << endl;
    }

    if (number == 2) {
        
        cout << "\nFor Take-out option" << endl;

        takeout take1;

        int takeoutType;

        cout << "Select package type: " << endl;
        cout << "For Regular, press 1" << endl;
        cout << "For Premium, press 2" << endl;

        cin >> takeoutType;
        

        if (takeoutType == 2) {
            cout << "$2.50 added" << endl;
        }

        take1.set_packageType(takeoutType);

        cout << "Package Type: " << take1.get_packageType() << endl;
    }

    return 0;
}
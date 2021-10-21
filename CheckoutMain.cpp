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
    cin >> number; // input for number for checkout Option


    test1.checkout_options(number);

    cout << "Checkout option: " << test1.get_option() << endl;
    // output checkout option

    // IF DINE-IN SELECTED
    if (number == 1) {

        int tableNumber;

        cout << "\nFor Dine-in option" << endl;
        cout << "Enter table number: ";
        cin >> tableNumber; // input for table number

        dinein check1;
        check1.set_table_number(tableNumber);

        cout << "Table number: " << check1.get_table_number() << endl;
    }

    // IF OUTPUT SELECTED
    if (number == 2) {
        
        cout << "\nFor Take-out option" << endl;

        takeout take1;

        int takeoutType;

        cout << "Select package type: " << endl;
        cout << "For Regular, press 1" << endl;
        cout << "For Premium, press 2" << endl;

        cin >> takeoutType; // input number for package type
        

        if (takeoutType == 2) {
            cout << "$2.50 added" << endl; // notify user to add extra costs
            // this part to be connected with outher componenets
        }

        take1.set_packageType(takeoutType);

        cout << "Package Type: " << take1.get_packageType() << endl;
    }

    return 0;
}
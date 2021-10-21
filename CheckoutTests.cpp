#include <iostream>
#include <string>

#include "Checkout.h"

using namespace std;

int main() {

    // TEST ONEE

    cout << "Test 1: Dine in, Table number 15" << endl;
    checkout test1;
    int number1 = 1;
    test1.checkout_options(number1);
    cout << test1.get_option() << endl;
    if (number1 == 1) {

        dinein check1;
        check1.set_table_number(15);

        cout << check1.get_table_number() << endl;
    }

    if (number1 == 2) {
        
        cout << "\nFor Take-out option" << endl;

        takeout take1;

        int takeoutType = 1;
        if (takeoutType == 2) {
            cout << "$2.50 added" << endl;
        }

        take1.set_packageType(takeoutType);

        cout << take1.get_packageType() << endl;
    }

    // TEST TWOO

    cout << "\nTest 2: Takeout, Regular" << endl;
    checkout test2;
    int number2 = 2;
    test2.checkout_options(number2);
    cout << test2.get_option() << endl;
    if (number2 == 1) {

        int tableNumber = 35;
        dinein check2;
        check2.set_table_number(tableNumber);

        cout << check2.get_table_number() << endl;
    }

    if (number2 == 2) {
        
        cout << "\nFor Take-out option" << endl;

        takeout take2;

        int takeoutType = 1;

        if (takeoutType == 2) {
            cout << "$2.50 added" << endl;
        }

        take2.set_packageType(takeoutType);

        cout << take2.get_packageType() << endl;
    }

    // TEST THREEE

    cout << "\nTest 3: Takeout, Premium" << endl;
    checkout test3;
    int number = 2;
    test3.checkout_options(number);
    cout << test3.get_option() << endl;
    if (number == 1) {

        int tableNumber = 84;

        dinein check2;
        check2.set_table_number(tableNumber);

        cout << check2.get_table_number() << endl;
    }

    if (number == 2) {
        
        cout << "\nFor Take-out option" << endl;

        takeout take2;

        int takeoutType = 2;

        if (takeoutType == 2) {
            cout << "$2.50 added" << endl;
        }

        take2.set_packageType(takeoutType);

        cout << take2.get_packageType() << endl;
    }

     // TEST FOURR

    cout << "Test 4: Dine in, Table number 7" << endl;
    checkout test4;
    int number4 = 1;
    test1.checkout_options(number4);
    cout << test1.get_option() << endl;
    if (number4 == 1) {

        dinein check4;
        check4.set_table_number(7);

        cout << check4.get_table_number() << endl;
    }

    if (number4 == 2) {
        
        cout << "\nFor Take-out option" << endl;

        takeout take4;

        int takeoutType = 1;
        if (takeoutType == 2) {
            cout << "$2.50 added" << endl;
        }

        take4.set_packageType(takeoutType);

        cout << take4.get_packageType() << endl;
    }

    // TEST FIVEE

    cout << "Test 5: Dine in, Table number 54.87, Output: 54" << endl;
    checkout test5;
    int number5 = 1;
    test5.checkout_options(number5);
    cout << test5.get_option() << endl;
    if (number5 == 1) {

        dinein check5;
        check5.set_table_number(54.87);

        cout << check5.get_table_number() << endl;
    }

    if (number5 == 2) {
        
        cout << "\nFor Take-out option" << endl;

        takeout take5;

        int takeoutType = 1;
        if (takeoutType == 2) {
            cout << "$2.50 added" << endl;
        }

        take5.set_packageType(takeoutType);

        cout << take5.get_packageType() << endl;
    }

    // TEST SIXX

    cout << "Test 6: Dine in, Table number: play, Output: will not compile + errors" << endl;
    
    /** cout << "Test 6: Dine in, Table number: play, Output: will not compile + errors" << endl;
    checkout test6;
    int number6 = play;
    test6.checkout_options(number5);
    cout << "Checkout option: " << test6.get_option() << endl;
    if (number6 == 1) {

        dinein check6;
        check6.set_table_number(54.87);

        cout << "Table number: " << check6.get_table_number() << endl;
    }

    if (number6 == 2) {
        
        cout << "\nFor Take-out option" << endl;

        takeout take6;

        int takeoutType = 1;
        if (takeoutType == 2) {
            cout << "$2.50 added" << endl;
        }

        take6.set_packageType(takeoutType);

        cout << take6.get_packageType() << endl;
    } **/
}


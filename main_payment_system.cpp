//
//  payment_system.cpp
//  
//
//  Created by Jonty Leslie on 5/10/21.
//

#include "payment_system.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

// PAYMENT PARENT

int main(){
    
    string choice = "credit_card";
    
    
    cout << endl << "Test 1 (Max, $15 order, $500 balance):" << endl;
    payment order(15, "Max", 74, 52);
    credit_card Max(500, order);
    Max.pay();
    
    cout << endl << "Test 2 (Maxxine, $15 order, $10 balance):" << endl;
    credit_card Maxxine(10, order);
    Maxxine.pay();
    
    cout << endl << "Test 3 (Chippy, $4 order, $10 balance):" << endl;
    payment order2(4, "Chips", 75, 53);
    credit_card chippy(10, order);
    chippy.pay();
    cout << endl;
    
    
    //payment p;
    /*
    if (choice == "credit_card") {
        p = credit_card();
    } else if (choice == "paypal"){
        p = paypal();
    }
    else if (choice == "cash"){
        p = cash();
    }
    else{
        cout << "Choice not recognised. Re-enter: ";
        cin >> choice;
    }
    
    p.pay();*/
    
    
   // cout << "test" << endl;


    
    
    return 0;
    
}

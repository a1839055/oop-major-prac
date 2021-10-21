#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>

#include "payment_system.h"

using namespace std;

// Payment PARENT

Payment::Payment(){
    
};

Payment::Payment(float p_price, string p_customer_name, int order_num, int receipt_num, string p_order_name){
    price = p_price;
    order_id = order_num;
    receipt_number = receipt_num;
    customer_name = p_customer_name;
    order_name = p_order_name;
};


string Payment::get_name(){
    return order_name;
}


bool Payment::pay(){
    return false;
};

Payment::~Payment(){
    
};


// CASH

 Cash::Cash(){
     cash_till_balance = 50;
 };

Cash::Cash(float p_price, string p_customer_name, int order_num, int receipt_num, string p_order_name){
    price = p_price;
    order_id = order_num;
    receipt_number = receipt_num;
    customer_name = p_customer_name;
    order_name = p_order_name;
    balance = 100;
    cash_till_balance = 50;
    cout << "Cash till balance: " << cash_till_balance << endl;
};

 void Cash::cash_till(){
     balance = balance - price;
     cash_till_balance = cash_till_balance + price;
     cout << "Updated Cash till balance: " << cash_till_balance << endl;
     return;
 };

 bool Cash::pay(){
     if(balance >= price) {
         cash_till();
         cout << "Payment successful." << endl;
         cout << "Your new balance is $" << balance << endl;
             return true;
     }
     else{
         cout << "Payment unsuccessful." << endl;
         cout << "Not enough funds." << endl;
         return false;
     }

 };

 Cash::~Cash(){
    
 };


// PAYPAL

Paypal::Paypal(){
    
};

Paypal::Paypal(float p_price, string p_customer_name, int order_num, int receipt_num, string p_order_name){
    price = p_price;
    order_id = order_num;
    receipt_number = receipt_num;
    customer_name = p_customer_name;
    order_name = p_order_name;
    paypal_balance = 100;
};

float Paypal::get_paypal_balance(){
    return paypal_balance;
};

bool Paypal::connect_to_paypal_servers(){
    return false;
};

bool Paypal::pay() {
    
    cout << "Enter PayPal username: " << endl;
    cin >> paypal_username;
    cout << "Enter PayPal password (should be same as username): " << endl;
    cin >> paypal_password;
    if (paypal_username == paypal_password && paypal_username == customer_name){
        cout << "Log-in successful" << endl;
    }
    else {
        cout << "Log-in un-successful. Exiting" << endl;
        return false;
    }
    
    if (paypal_balance >= price){
        paypal_balance = paypal_balance - price;
        cout << "Payment successful." << endl;
        cout << "Your new balance is $" << paypal_balance << endl;
        return true;
    }
    else {
        cout << "Payment unsuccessful." << endl;
        cout << "Not enough funds." << endl;
        return false;
    }
};



Paypal::~Paypal(){
    
};


// CREDIT CARD

 CreditCard::CreditCard(){
     cout << "No balance obtained. Exiting program." << endl;
     return;
 };

CreditCard::CreditCard(float p_price, string p_customer_name, int order_num, int receipt_num, string p_order_name){
    price = p_price;
    order_id = order_num;
    receipt_number = receipt_num;
    customer_name = p_customer_name;
    order_name = p_order_name;
    bank_balance = 100;
}

 bool CreditCard::pay(){
     if(bank_balance >= price){
         bank_balance = bank_balance - price;
         cout << "Payment successful." << endl;
         cout << "Your new balance is $" << bank_balance << endl;
             return true;
     }
     else{
         cout << "Payment unsuccessful." << endl;
         cout << "Not enough funds." << endl;
         return false;
     }
 };

 bool CreditCard::connect_CreditCard_system(){
     return false;
 };

 CreditCard::~CreditCard(){
    
 };

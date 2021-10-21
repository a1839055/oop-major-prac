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


//Constructor with initialisation variables
Payment::Payment(float p_price, string p_customer_name, int order_num, int receipt_num, string p_order_name){
    price = p_price;
    order_id = order_num;
    receipt_number = receipt_num;
    customer_name = p_customer_name;
    order_name = p_order_name;
};

// Gets the name of the order
string Payment::get_name(){
    return order_name;
}

// No declaration in parent
bool Payment::pay(){
    return false;
};


//Destructor
Payment::~Payment(){
    
};


// CASH


 Cash::Cash(){
     cash_till_balance = 50; //Cash till always starts with $50
 };


// Cash constructor with initialisation variables
Cash::Cash(float p_price, string p_customer_name, int order_num, int receipt_num, string p_order_name){
    price = p_price; //price of the item
    order_id = order_num; //order id, unique
    receipt_number = receipt_num; //receipt number
    customer_name = p_customer_name; //customer's name
    order_name = p_order_name; //name of the order 
    balance = 100; //amount of cash user has
    cash_till_balance = 50; //amount of cash in cash till
    cout << "Cash till balance: " << cash_till_balance << endl; // prints out cash till balance
};


// This function takes money out of the cash till when necessary and prints the updated balance
 void Cash::cash_till(){ 
     balance = balance - price;
     cash_till_balance = cash_till_balance + price;
     cout << "Updated Cash till balance: " << cash_till_balance << endl;
     return;
 };


// Payment method for cash class
 bool Cash::pay(){
     if(balance >= price) { // If user can afford item
         cash_till(); // Opens up and updates cash till
         cout << "Payment successful." << endl; // Notifies user that the payment was successful
         cout << "Your new balance is $" << balance << endl; //prints out the new balance
             return true; // returns successful
     }
     else{ // If user can't afford item
         cout << "Payment unsuccessful." << endl; // notifies user that they don't have enough funds
         cout << "Not enough funds." << endl;
         return false; // returns unsuccessful
     }

 };

 Cash::~Cash(){ //destructor
    
 };


// PAYPAL

Paypal::Paypal(){
    
};

// Initialises paypal variables with constructor
Paypal::Paypal(float p_price, string p_customer_name, int order_num, int receipt_num, string p_order_name){
    price = p_price; //price of the item
    order_id = order_num; //order id, unique
    receipt_number = receipt_num; //receipt number
    customer_name = p_customer_name; //customer's name
    order_name = p_order_name; //name of the order 
    paypal_balance = 100; // The user's paypal balance
};

// gets the paypal balance
float Paypal::get_paypal_balance(){
    return paypal_balance;
};

bool Paypal::connect_to_paypal_servers(){
    return false;
};


// payment method for paypal
bool Paypal::pay() {
    
    cout << "Enter PayPal username: " << endl; // prompts and obtains paypal username
    cin >> paypal_username;
    cout << "Enter PayPal password (should be same as username): " << endl; // prompts and obtains users password
    cin >> paypal_password;
    if (paypal_username == paypal_password && paypal_username == customer_name){ // checks if the password and username is correct
        cout << "Log-in successful" << endl;
    } // notifies whether login is successful or not
    else {
        cout << "Log-in un-successful. Exiting" << endl;
        return false;
    }
    
    if (paypal_balance >= price){ //if user can afford item
        paypal_balance = paypal_balance - price;
        cout << "Payment successful." << endl;
        cout << "Your new balance is $" << paypal_balance << endl; // notifies new balance
        return true;
    }
    else { //if user can't afford item it returns unsuccessful and notifies user
        cout << "Payment unsuccessful." << endl;
        cout << "Not enough funds." << endl;
        return false;
    }
};



Paypal::~Paypal(){ // destructor
    
};


// CREDIT CARD

 CreditCard::CreditCard(){ //if no balance is obtained
     cout << "No balance obtained. Exiting program." << endl;
     return;
 };

// Credit card constructor with initialisation variables
CreditCard::CreditCard(float p_price, string p_customer_name, int order_num, int receipt_num, string p_order_name){
    price = p_price; //price of the item
    order_id = order_num; //order id, unique
    receipt_number = receipt_num; //receipt number
    customer_name = p_customer_name; //customer's name
    order_name = p_order_name; //name of the order 
    bank_balance = 100; // bank balance 
}

// Credit card payment method
 bool CreditCard::pay(){
     if(bank_balance >= price){ // if user can afford the item
         bank_balance = bank_balance - price; 
         cout << "Payment successful." << endl;
         cout << "Your new balance is $" << bank_balance << endl;
             return true; 
     }
     else{ // if user cannot afford the item
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

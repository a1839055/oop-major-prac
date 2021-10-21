#include "Payment_system.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

// Payment PARENT

Payment::Payment(){ //Class constructor
    
};

//Class constructor with initialisation methods
Payment::Payment(float p_price, string p_customer_name, int order_num, int receipt_num, string pOrder_name){ 
    price = p_price;
    order_id = order_num;
    receipt_number = receipt_num;
    customer_name = p_customer_name;
    order_name = pOrder_name;
};

void Payment::send_Payment_info(){
    
};

void Payment::send_order_to_kitchen(){
    
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

Cash::Cash(float p_balance, Payment p_class_name){
    balance = p_balance;
    placeholder = p_class_name;
    cash_till_balance = 50;
    cout << "Cash till balance: " << cash_till_balance << endl;
};

void Cash::cash_till(){
    balance = balance - placeholder.price;
    cash_till_balance = cash_till_balance + placeholder.price;
    cout << "Updated Cash till balance: " << cash_till_balance << endl;
    return;
};

bool Cash::pay(){
    if(balance >= placeholder.price){
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

Paypal::Paypal(float p_paypal_balance, Payment class_name){
    paypal_balance = p_paypal_balance;
    placeholder = class_name;
};


bool Paypal::connect_to_paypal_servers(){
    return false;
};

bool Paypal::pay(){
    
    cout << "Enter PayPal username: " << endl;
    cin >> paypal_username;
    cout << "Enter PayPal password (should be same as username): " << endl;
    cin >> paypal_password;
    if(paypal_username == paypal_password && paypal_username == placeholder.customer_name){
        cout << "Log-in successful" << endl;
    }
    else{
        cout << "Log-in un-successful. Exiting" << endl;
        return false;
    }
    
    if(paypal_balance >= placeholder.price){
        paypal_balance = paypal_balance - placeholder.price;
        cout << "Payment successful." << endl;
        cout << "Your new balance is $" << paypal_balance << endl;
            return true;
    }
    else{
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

CreditCard::CreditCard(float p_bank_balance, Payment class_name){
    bank_balance = p_bank_balance;
    placeholder = class_name;
};


bool CreditCard::pay(){
    if(bank_balance >= placeholder.price){
        bank_balance = bank_balance - placeholder.price;
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

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

payment::payment(){
    
};

payment::payment(float pPrice, string pCustomerName, int orderNum, int receiptNum){
    price = pPrice;
    order_id = orderNum;
    receipt_number = receiptNum;
    customer_name = pCustomerName;
};

void payment::send_payment_info(){
    
};

void payment::send_order_to_kitchen(){
    
};
/*
bool payment::pay(int method, payment payClassName){
    switch (method){
    case 0:
        
        payClassName.cash::pay();
        break;
    case 1:
        payClassName.paypal::pay();
        break;
    case 2:
        payClassName.credit_card::pay();
        break;
    }
};*/

bool payment::pay(){
    return false;
};

payment::~payment(){
    
};


// CASH

cash::cash(){
    cash_till_balance = 50;
};

cash::cash(float pBalance, payment pClassName){
    balance = pBalance;
    placeholder = pClassName;
    cash_till_balance = 50;
    cout << "Cash till balance: " << cash_till_balance << endl;
};

void cash::cash_till(){
    balance = balance - placeholder.price;
    cash_till_balance = cash_till_balance + placeholder.price;
    cout << "Updated cash till balance: " << cash_till_balance << endl;
    return;
};

bool cash::pay(){
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

cash::~cash(){
    
};


// PAYPAL

paypal::paypal(){
    
};

paypal::paypal(float pPayPalBalance, payment className){
    paypal_balance = pPayPalBalance;
    placeholder = className;
};


bool paypal::connect_to_paypal_servers(){
    return false;
};

bool paypal::pay(){
    
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



paypal::~paypal(){
    
};


// CREDIT CARD

credit_card::credit_card(){
    cout << "No balance obtained. Exiting program." << endl;
    return;
};

credit_card::credit_card(float pBankBalance, payment className){
    bank_balance = pBankBalance;
    placeholder = className;
};


bool credit_card::pay(){
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

bool credit_card::connect_credit_card_system(){
    return false;
};

credit_card::~credit_card(){
    
};

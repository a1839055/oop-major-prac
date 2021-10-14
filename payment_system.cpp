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
    
};

cash::cash(float pBalance, payment pClassName){
    balance = pBalance;
    //cashPlace = pClassName;
};

int cash::cash_till(){
    
    return 0;
};

bool cash::pay(){
  /*  if(balance > cashPlace.price){
        balance = balance - cashPlace.price;
        cout << "Payment successful." << endl;
        cout << "Your new balance is $" << balance << endl;
            return true;
    }
    else{
        cout << "Payment unsuccessful." << endl;
        cout << "Not enough funds." << endl;
        return false;
    }*/
    return false;
};

cash::~cash(){
    
};


// PAYPAL

paypal::paypal(){
    
};

paypal::paypal(float pPayPalBalance, payment className){
    
};


bool paypal::connect_to_paypal_servers(){
    return false;
};

bool paypal::pay(){
    return false;
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
    if(bank_balance > placeholder.price){
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

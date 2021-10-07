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

Payment::Payment(){
    
};

void Payment::send_payment_info(){
    
};

void Payment::send_order_to_kitchen(){
    
};

bool Payment::pay(){
    
};

Payment::~Payment(){
    
};


// CASH

Cash::Cash(){
    
};

int Cash::cash_till(){
    
};

bool Cash::pay(){
    
};

Cash::~Cash(){
    
};


// PAYPAL

PayPal::PayPal(){
    
};

bool PayPal::connect_to_paypal_servers(){
    
};

bool PayPal::pay(){
    
};

PayPal::~PayPal(){
    
};


// CREDIT CARD

CreditCard::CreditCard(){
    
};

bool CreditCard::pay(){
    
};

bool CreditCard::connect_credit_card_system(){
    
};

CreditCard::~CreditCard(){
    
};

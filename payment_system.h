//
//  payment_system.hpp
//  
//
//  Created by Jonty Leslie on 5/10/21.
//

#ifndef payment_system_hpp
#define payment_system_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

class Payment {
    private:
    
    public:
        Payment();
        float price;
        string customer_name;
        int order_id;
        int receipt_number;
        bool is_payment_success;
        void send_payment_info();
        void send_order_to_kitchen();
        virtual bool pay();
        ~Payment(); //destructor
};

class Cash : public Payment{
    private:
        int cash_types[3];
    public:
        Cash();
        float balance;
        int cash_till();
        bool pay();
        ~Cash();
};

class PayPal : public Payment {
    private:
        string paypal_username;
        string paypal_password;
    public:
        PayPal();
        string paypal_balance;
        bool connect_to_paypal_servers();
        bool pay();
        ~PayPal();
};

class CreditCard : public Payment{
    private:
        int cc_number;
        string cc_name;
        int ccv;
    public:
        CreditCard();
        float bank_balance;
        bool connect_credit_card_system();
        bool pay();
        ~CreditCard();
    
};

#endif /* payment_system_hpp */

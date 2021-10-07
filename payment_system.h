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

class payment{
    private:
    
    public:
        payment();
        float price;
        string customer_name;
        int order_id;
        int receipt_number;
        bool is_payment_success;
        void send_payment_info();
        void send_order_to_kitchen();
        virtual bool pay();
        ~payment(); //destructor
};

class cash : public payment{
    private:
        int cash_types[3];
    public:
        cash();
        float balance;
        int cash_till();
        bool pay();
        ~cash();
};

class paypal : public payment{
    private:
        string paypal_username;
        string paypal_password;
    public:
        paypal();
        string paypal_balance;
        bool connect_to_paypal_servers();
        bool pay();
        ~paypal();
};

class credit_card : public payment{
    private:
        int cc_number;
        string cc_name;
        int ccv;
    public:
        credit_card();
        float bank_balance;
        bool connect_credit_card_system();
        bool pay();
        ~credit_card();
    
};

#endif /* payment_system_hpp */

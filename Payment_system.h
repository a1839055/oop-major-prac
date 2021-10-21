
#ifndef Payment_system_hpp
#define Payment_system_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

class Payment{
    private:
    
    public:
        Payment();
        Payment(float p_price, string p_customer_name, int order_num, int receipt_num, string order_name);
        float price;
        string customer_name;
        string order_name;
        int order_id;
        int receipt_number;
        bool is_Payment_success;
        void send_Payment_info();
        void send_order_to_kitchen();
        virtual bool pay(); //pure virtual function
        virtual string get_name();
        ~Payment(); //destructor
};

class Cash : public Payment{
    public:
        Cash();
        Cash(float p_balance, Payment p_class_name);
        float cash_till_balance;
        float balance;
        Payment placeholder;
        void cash_till();
        bool pay();
        ~Cash();
};

class Paypal : public Payment{
    private:
        string paypal_username;
        string paypal_password;
    public:
        Paypal();
        Paypal(float p_paypal_balance, Payment class_name);
        float paypal_balance;
        Payment placeholder;
        bool connect_to_paypal_servers();
        bool pay();
        ~Paypal();
};

class CreditCard : public Payment{
    private:
        int cc_number;
        string cc_name;
        int ccv;
    public:
        CreditCard();
        CreditCard(float p_bank_balance, Payment class_name);
        Payment placeholder;
        float bank_balance;
        bool connect_CreditCard_system();
        bool pay();
        ~CreditCard();
    
};

#endif /* Payment_system_hpp */

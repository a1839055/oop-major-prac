
#ifndef Payment_system_hpp
#define Payment_system_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

class Payment{
    protected:
        float price;
        string customer_name;
        string order_name;
        int order_id;
        int receipt_number;
        bool is_Payment_success;
    public:
        Payment();
        Payment(float p_price, string p_customer_name, int order_num, int receipt_num, string order_name);
        ~Payment(); //destructor
        

        virtual bool pay() = 0; //pure virtual function
        virtual string get_name();
};


class Paypal : public Payment{
    private:
        string paypal_username;
        string paypal_password;
        float paypal_balance;
        float get_paypal_balance();
    public:
        Paypal();
        Paypal(float p_price, string p_customer_name, int order_num, int receipt_num, string order_name);
        // Payment placeholder;
        bool connect_to_paypal_servers();
        bool pay();
        ~Paypal();
};

// class Cash : public Payment{
//     public:
//         Cash();
//         Cash(float p_balance, Payment p_class_name);
//         float cash_till_balance;
//         float balance;
//         // Payment placeholder;
//         void cash_till();
//         bool pay();
//         ~Cash();
// };

// class CreditCard : public Payment{
//     private:
//         int cc_number;
//         string cc_name;
//         int ccv;
//     public:
//         CreditCard();
//         CreditCard(float p_bank_balance, Payment class_name);
//         // Payment placeholder;
//         float bank_balance;
//         bool connect_CreditCard_system();
//         bool pay();
//         ~CreditCard();
    
// };

#endif /* Payment_system_hpp */

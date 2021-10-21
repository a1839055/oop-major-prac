
#include "Payment_system.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

// Payment PARENT

int main(){
    
    string choice = "CreditCard";
    
    
    cout << endl << "Test 1 (credit card) (Max, $15 order, $500 balance):" << endl;
    cout << "Expected result: Pass with $485 spare." << endl;
    Payment order(15, "Max", 74, 52, "order");
    CreditCard Max(500, order);
    Max.pay();
    
    cout << endl << "Test 2 (credit card) (Maxxine, $15 order, $10 balance):" << endl;
    cout << "Expected result: Fail, not enough money." << endl;
    CreditCard Maxxine(10, order);
    Maxxine.pay();
    
    cout << endl << "Test 3 (credit card) (Chippy, $4 order, $10 balance):" << endl;
    cout << "Expected result: Pass with $6 spare." << endl;
    Payment order2(4, "Chips", 75, 53, "order2");
    CreditCard chippy(10, order2);
    chippy.pay();
    cout << endl;
    
    cout << endl << "Test 4 (Paypal) (John, $4 order, $50 PayPal balance):" << endl;
    cout << "Expected result: Pass with $46 if log-in is successful." << endl;
    Payment order3(4, "John", 75, 53, "order3");
    Paypal John(50, order3);
    cout << "Customer: " << order3.customer_name << endl;
    John.pay();
    cout << endl;
    
    cout << endl << "Test 5 (Cash) (Karen, $14 order, $25 Cash balance):" << endl;
    cout << "Expected result: Pass with $11 spare and $64 in Cash till." << endl;
    Payment order4(14, "Karen", 76, 55, "order4");
    Cash Karen(25, order4);
    cout << "Customer: " << order4.customer_name << endl;
    Karen.pay();
    cout << endl;
    
    cout << endl << "Test 6 (Cash) (Muzza, $21 order, $20 Cash balance):" << endl;
    cout << "Expected result: Fail, not enough funds." << endl;
    Payment order5(21, "Muzza", 77, 80, "order5");
    Cash Muzza(20, order5);
    cout << "Customer: " << order5.customer_name << endl;
    Muzza.pay();
    cout << endl;
    
    cout << endl << "Test 7 (Paypal) (Jackery, $7 order, $0 PayPal balance):" << endl;
    cout << "Expected result: Fail regardless of log-in." << endl;
    Payment order6(7, "Jackery", 78, 81, "order6");
    Cash Jackery(0, order6);
    cout << "Customer: " << order6.customer_name << endl;
    Jackery.pay();
    cout << endl;
    
    cout << endl << "Test 8 (Cash) (Mirendara, $1 order, $0 credit card balance):" << endl;
    cout << "Expected result: Fail regardless of credit card details." << endl;
    Payment order7(1, "Mirendara", 78, 81, "order7");
    Cash Mirendara(0, order7);
    cout << "Customer: " << order7.customer_name << endl;
    Mirendara.pay();
    cout << endl;
    
    cout << endl << "Test 9 (Paypal) (Ntera, $10 order, $10 PayPal balance):" << endl;
    cout << "Expected result: Pass with $0 spare if log-in is successful." << endl;
    Payment order8(10, "Ntera", 75, 53, "order8");
    Paypal Ntera(10, order8);
    cout << "Customer: " << order8.customer_name << endl;
    Ntera.pay();
    cout << endl;
    
    cout << "UNIT TESTING" << endl;
    cout << "Testing making a Payment class (called 'test'): " << endl;
    Payment test(10, "Test 1", 1, 1, "test");
    cout << "Expected: Cost $10, Customer name Test 1, Order ID 1, Receipt Number 1" << endl;
    cout << "Payment class:" << endl << "Cost: " << test.price << ". Customer name: " << test.customer_name << ". Order ID: " << test.order_id << ". Receipt number: " << test.receipt_number << "." << endl;
    
    cout << "Testing making an order based on test 1 (Cash): " << endl;
    //Payment test(10, "Test 1", 1, 1);
    Cash test1(10, test);
    cout << "Expected: Cash balance $10, Order based on: 'test'" << endl;
    cout << "Balance: " << test1.balance << ". Order: " << test.get_name() << "." << endl;
    
    
    return 0;
    
}

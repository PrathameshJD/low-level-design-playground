#include<iostream>

using namespace std;

class PaymentService{
public: 
    void pay(double amount, string paymentMethod){
        if (paymentMethod == "UPI") {
            cout << "Paid Rs." << amount << " using UPI" << endl;
        }
        else if (paymentMethod == "CARD") {
            cout << "Paid Rs." << amount << " using Credit Card" << endl;
        }
        else if (paymentMethod == "PAYPAL") {
            cout << "Paid Rs." << amount << " using PayPal" << endl;
        }
        else {
            cout << "Invalid payment method" << endl;
        }
    }
};

int main(){
    PaymentService paymentService;

    paymentService.pay(1000,"UPI");
    paymentService.pay(2000,"CARD");

    return 0;
}
#include<iostream>
#include<memory>

using namespace std;

// Strategy Interface (abstract)
class PaymentStrategy{
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentStrategy() = default;
};


// Strategy 1
class UpiPayment : public PaymentStrategy{
public:
    void pay(double amount) override {
        cout << "Paid Rs." << amount << " using UPI" << endl;
    }
};

// Strategy 2
class CardPayment : public PaymentStrategy{
public:
    void pay(double amount) override {
        cout << "Paid Rs." << amount << " using Card" << endl;
    } 
};

// Strategy 3
class PayPalPayment : public PaymentStrategy{
public:
    void pay(double amount) override {
        cout << "Paid Rs." << amount << " using PayPal" << endl;
    }
};

// Context
class PaymentContext {
private:
    unique_ptr<PaymentStrategy> paymentStrategy;
public:
    PaymentContext(unique_ptr<PaymentStrategy> p){
        this->paymentStrategy = move(p);
    }

    void setStrategy(unique_ptr<PaymentStrategy> p){
        this->paymentStrategy = move(p);
    }

    void pay(double amount){
        paymentStrategy->pay(amount);
    }

};

// Client
int main(){
    
    PaymentContext paymentContext (make_unique<UpiPayment>());
    paymentContext.pay(1000);

    paymentContext.setStrategy(make_unique<CardPayment>());
    paymentContext.pay(2000);

    paymentContext.setStrategy(make_unique<PayPalPayment>());
    paymentContext.pay(3000);

    return 0;
}
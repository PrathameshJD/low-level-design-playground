#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Coffee {
public:
    virtual ~Coffee() = default;

    virtual string description() const = 0;
    virtual double cost() const = 0;
};

// Base Coffee
class SimpleCoffee : public Coffee {
public:
    string description() const override {
        return "Coffee";
    }

    double cost() const override {
        return 50.0;
    }
};

// Coffee + Milk
class MilkCoffee : public Coffee {
public:
    string description() const override {
        return "Coffee + Milk";
    }

    double cost() const override {
        return 70.0;
    }
};

// Coffee + Sugar
class SugarCoffee : public Coffee {
public:
    string description() const override {
        return "Coffee + Sugar";
    }

    double cost() const override {
        return 60.0;
    }
};

// Coffee + Chocolate
class ChocolateCoffee : public Coffee {
public:
    string description() const override {
        return "Coffee + Chocolate";
    }

    double cost() const override {
        return 80.0;
    }
};

// Coffee + Milk + Sugar
class MilkSugarCoffee : public Coffee {
public:
    string description() const override {
        return "Coffee + Milk + Sugar";
    }

    double cost() const override {
        return 80.0;
    }
};

// Coffee + Milk + Chocolate
class MilkChocolateCoffee : public Coffee {
public:
    string description() const override {
        return "Coffee + Milk + Chocolate";
    }

    double cost() const override {
        return 100.0;
    }
};

// Coffee + Sugar + Chocolate
class SugarChocolateCoffee : public Coffee {
public:
    string description() const override {
        return "Coffee + Sugar + Chocolate";
    }

    double cost() const override {
        return 90.0;
    }
};

// Coffee + Milk + Sugar + Chocolate
class MilkSugarChocolateCoffee : public Coffee {
public:
    string description() const override {
        return "Coffee + Milk + Sugar + Chocolate";
    }

    double cost() const override {
        return 110.0;
    }
};

int main() {
    unique_ptr<Coffee> coffee =  make_unique<SugarChocolateCoffee>();

    cout << coffee->description() << '\n';
    cout << "Cost: ₹" << coffee->cost() << '\n';
}
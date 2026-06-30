#include <iostream>
#include <memory>
#include <string>

class Coffee {
public:
    virtual ~Coffee() = default;

    virtual std::string description() const = 0;
    virtual double cost() const = 0;
};

class SimpleCoffee : public Coffee {
public:
    std::string description() const override {
        return "Coffee";
    }

    double cost() const override {
        return 50;
    }
};

class CoffeeDecorator : public Coffee {
protected:
    std::unique_ptr<Coffee> coffee;

public:
    explicit CoffeeDecorator(std::unique_ptr<Coffee> c)
        : coffee(std::move(c))
    {
    }
};

class MilkDecorator : public CoffeeDecorator {
public:
    explicit MilkDecorator(std::unique_ptr<Coffee> c)
        : CoffeeDecorator(std::move(c))
    {
    }

    std::string description() const override {
        return coffee->description() + " + Milk";
    }

    double cost() const override {
        return coffee->cost() + 20;
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    explicit SugarDecorator(std::unique_ptr<Coffee> c)
        : CoffeeDecorator(std::move(c))
    {
    }

    std::string description() const override {
        return coffee->description() + " + Sugar";
    }

    double cost() const override {
        return coffee->cost() + 10;
    }
};

class ChocolateDecorator : public CoffeeDecorator {
public:
    explicit ChocolateDecorator(std::unique_ptr<Coffee> c)
        : CoffeeDecorator(std::move(c))
    {
    }

    std::string description() const override {
        return coffee->description() + " + Chocolate";
    }

    double cost() const override {
        return coffee->cost() + 30;
    }
};

int main() {

    std::unique_ptr<Coffee> coffee =
        std::make_unique<SimpleCoffee>();

    coffee = std::make_unique<MilkDecorator>(std::move(coffee));

    coffee = std::make_unique<SugarDecorator>(std::move(coffee));

    coffee = std::make_unique<ChocolateDecorator>(std::move(coffee));

    std::cout << coffee->description() << '\n';
    std::cout << "Cost : " << coffee->cost() << '\n';
}
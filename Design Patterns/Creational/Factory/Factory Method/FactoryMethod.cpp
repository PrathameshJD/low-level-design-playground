#include<iostream>
#include<memory>

using namespace std;

// Product Interface
class Vehicle{
public:
    virtual void drive() = 0;
    virtual ~Vehicle() = default;
};

// Concrete Product
class Car : public Vehicle{
public:
    void drive() override{
        cout << "Driving Car" << endl;
    }
};

// Concrete Product
class Bus : public Vehicle{
public:
    void drive() override{
        cout << "Driving Bus" << endl;
    }
};

// Concrete Product
class Truck : public Vehicle{
public:
    void drive() override{
        cout << "Driving Truck" << endl;
    }
};

// Factory Interface
class VehicleFactory{
public:
    virtual unique_ptr<Vehicle> createVehicle() = 0;
};

// Concrete Factory
class CarFactory : public VehicleFactory{
public:
    unique_ptr<Vehicle> createVehicle() override{
        return make_unique<Car>();
    }
};

// Concrete Factory
class BusFactory : public VehicleFactory{
public:
    unique_ptr<Vehicle> createVehicle() override{
        return make_unique<Bus>();
    }
};

// Concrete Factory
class TruckFactory : public VehicleFactory{
public:
    unique_ptr<Vehicle> createVehicle() override{
        return make_unique<Truck>();
    }
};

// Client
int main(){
    unique_ptr<VehicleFactory> factory;

    factory = make_unique<CarFactory>();
    factory->createVehicle()->drive();

    factory = make_unique<BusFactory>();
    factory->createVehicle()->drive();

    factory = make_unique<TruckFactory>();
    factory->createVehicle()->drive();

    return 0;
}
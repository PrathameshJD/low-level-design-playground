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

// Factory
class VehicleFactory{
public:
    unique_ptr<Vehicle> createVehicle(string type){
        if(type == "car"){
            return make_unique<Car>();
        }else if(type == "bus"){
            return make_unique<Bus>();
        }else{
            cout << "Invalid Type" << endl;
            return nullptr;
        }
    } 
};

// Client
int main(){
    unique_ptr<VehicleFactory> factory = make_unique<VehicleFactory>();

    unique_ptr<Vehicle> vehicle = factory->createVehicle("car");

    if(vehicle)
        vehicle->drive();

    return 0;
}
#include<iostream>
#include<vector>

using namespace std;

class TwoDimensionalShape {
public:
    virtual ~TwoDimensionalShape() = default;
    virtual double area() = 0;
};

class ThreeDimensionalShape{
public:
    virtual ~ThreeDimensionalShape() = default;

    virtual double area() = 0;
    virtual double volume() = 0;
};

class Square : public TwoDimensionalShape{
private:
    double side;
public:     
    Square(double side){
        this->side = side ;
    }

    double area(){
        return side * side ;
    }
};


class Cube : public ThreeDimensionalShape{
private: 
    double side;

public:
    Cube(double side){
        this->side = side;
    }

    double area(){
        return 6 * side * side;
    }

    double volume(){
        return side * side * side;
    }
};


int main(){
    TwoDimensionalShape *square = new Square(4);

    ThreeDimensionalShape *cube = new Cube(4);

    cout << "Square Area : " << square->area() << endl;
    
    cout << "Cube Area : " << cube->area() << endl;

    cout << "Cube Volume : " << cube->volume() << endl;
}
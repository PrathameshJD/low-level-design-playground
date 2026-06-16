#include<iostream>
#include<vector>

using namespace std;

class Shape {
public:
    virtual double area()=0;
    virtual double volume()=0;

    virtual ~Shape() = default;
};

class Square : public Shape{
private:
    double side;

public:
    Square(double side){
        this->side = side;
    }

    double area(){
        return side*side;
    }

    double volume(){
        throw logic_error("Volume is not applicable!\n");
    }

};


class Rectangle : public Shape{
private:
    double length;
    double width;

public:
    Rectangle(double length, double width){
        this->length = length;
        this->width = width;
    }

    double area(){
        return length * width;
    }

    double volume(){
        throw logic_error("Volume is not applicable!\n");
    }

};

class Cube : public Shape{
private:
    double side;

public:
    Cube(double side){
        this->side = side;
    }    

    double area(){
        return 6*(side * side);
    }

    double volume(){
        return side * side * side;
    }

};


int main(){
    Shape *square = new Square(4);
    Shape *rectangle = new Rectangle(4,5);
    Shape *cube = new Cube(4);
    
    cout << "Square area : " << square->area() << endl;
    cout << "Rectangle area : " << rectangle->area() << endl;
    cout << "Cube area : " << cube->area() << endl;
    cout << "Cube volume : " << cube->volume() << endl;
    return 0;
}
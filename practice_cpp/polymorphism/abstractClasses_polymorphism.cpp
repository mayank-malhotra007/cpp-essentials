

#include <iostream>

// Abstract class //
class Shape {

    public:
    virtual void draw() = 0; // pure virtual functions

    virtual ~Shape(){}
};


class Circle : public Shape {


    public:
    void draw() override final
    {
        std::cout << "im a circle" << std::endl;
    }


};


class Square : public Shape {

      public:
    void draw() override final
    {
        std::cout << "im a square" << std::endl;
    }



};


int main() {

    Circle c;
    c.draw();

    Square s;
    s.draw();

   // Shape p;  // cant create an object for abstract classes

    Shape* ptr_circle = new Circle();
    Shape* ptr_square = new Square();

    ptr_circle->draw();
    ptr_square->draw();

    delete ptr_circle;
    delete ptr_square;
}


#include <iostream>

// only virtual functions can use keyword "final"

class Base {

    public:
         void display () 
        {
            std::cout << "Im from base" << std::endl;
        }
};



// since Derived is marked as "final", we cant inherit from it

class Derived  : public Base{

    public:
        virtual void display() final // display() cannot be used in classes derived from Derived class
        {
            std::cout << "Im from derived" << std::endl;
        }


};


/*
class Derived_Derived : Derived{

    public:
         void display () 
        {
            std::cout << "Im from base" << std::endl;
        }
};
*/




int main(){

    Base b;
    b.display();

    Derived d;
    d.display();

    Base* ptr = new Derived();
    ptr -> display();


    return 0;
}
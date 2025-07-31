
#include <iostream>


class A{


    public:
    A(){std::cout << "default constructor" << std::endl;}
    A(const A& rhs) {std::cout << "copy constructor" << std::endl;}
    A(A&& rhs) {std::cout << "move constructor" << std::endl;}

    

};


int main()
{
    A obj_1;
    A obj_2 {obj_1};
    A obj3 = std::move(obj_2);

    return 0;
}

#include <iostream>

int main() {
    
    int a = 100;
    const double b = 1000.10;
    int c = 200;
    const double d = 3.4;
    const float f = 10.5;
    const float x = 1.1;


    // constant pointer
    int* const ptr1 = &a;

    // pointer to a constant
    const double* ptr2 = &b;
    
    // constant pointer to a constant
    const float* const ptr3 = &f;
   
    std::cout << "ptr1 holds value: " << *ptr1 << std::endl;
    std::cout << "ptr2 holds value: " << *ptr2 << std::endl;

    // we can change value of variable a using ptr1 
    *ptr1 = 3000;
    std::cout << "now ptr1 holds value: " << *ptr1 << std::endl;
   
    // we cannot assign ptr1 to any other variable!
    //ptr1 = &c;  //compiler error

    // ptr2 can point to some other variable of same dataType
    ptr2 = &d;
    std::cout << "ptr2 now holds value: " << *ptr2 << std::endl;

    // but cannot change value to which it points
    //*ptr2 = 30000;  // compiler error

    // ptr3 can only point to one address and cannot modify its value
    //*ptr3=2.5;
    //ptr3=&x;
   
    std::cout << "ptr3 holds value: " << *ptr3 << std::endl;
    return 0;
}
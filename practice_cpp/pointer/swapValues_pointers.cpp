
#include <iostream>

int main() {

    int a = 10;
    int b = 5;

    int* ptr_a;
    int* ptr_b;

    ptr_a = &a;
    ptr_b = &b;

    int temp;
    temp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = temp;

    std::cout << "a is: " << a << std::endl;
    std::cout << "b is: " << b << std::endl;



    return 0;
}
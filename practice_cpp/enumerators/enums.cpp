
// enums are user defined datatypes; modelling a set of constant integral values

#include <iostream>


enum Color : uint8_t {Red, Green , Blue}; // 0,1,2 


int main() {

    

    Color mycolor;

    mycolor = Red;

    std::cout << "color is: " << static_cast<int>(mycolor) << std::endl;

    return 0;
}

/*
 MACROS and generic programming
*/

#include <iostream>


#define ADD(x,y) ((x)+(y))
#define MAX(x,y) ((x)>(y)?(x):(y))
#define SQUARE(x) ((x)*(x))
#define DIVIDE(x,y) ((x)/(y))


int main()
{

    std::cout << ADD(2,3) << std::endl;
    std::cout << ADD(2.5,3.5) << std::endl;
    std::cout << MAX(2,3) << std::endl;
    std::cout << MAX(2.5,3.7) << std::endl;
    std::cout << SQUARE(3) << std::endl;
    std::cout << DIVIDE(100,5) << std::endl;
    std::cout << DIVIDE(10,2.5) << std::endl;
    

    return 0;
}
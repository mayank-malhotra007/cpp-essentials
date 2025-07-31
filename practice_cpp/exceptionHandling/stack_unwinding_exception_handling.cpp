
#include <iostream>


void B(); // Forward declaration
void C(); // 


void A()
{
    std::cout << "starting function A" << std::endl;
    B();
    std::cout << "ending function A" << std::endl;
}




void B()
{
    std::cout << "starting function B" << std::endl;
    try {
        C();
    }
     catch(int& ex)
    {
        std::cerr << "exception caught in B" << std::endl;
    }
    std::cout << "ending function B" << std::endl;
}

void C()
{
    std::cout << "starting function C" << std::endl;
    throw 0; // this is like a jump, stack unwinding starts here.
    std::cout << "ending function C" << std::endl;
}



int main()
{

    try{
        A();
    }
    

    catch(int& ex)
    {
        std::cerr << "exception caught" << std::endl;
    }
    std::cout << "main ends" << std::endl;

    return 0;
}
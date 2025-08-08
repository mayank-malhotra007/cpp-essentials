
#include <iostream>
#include <iomanip>

int main() 
{

    double num {1234.56789};

    std::cout << num << std::endl;
    
    // setw()
    std::cout << std::setw(10) << num << std::endl;
    std::cout << std::setw(10) << std::left << num << std::endl;
    std::cout << std::setw(10) << std::right << num << std::endl;

    //setfill() will work with setw()
    std::cout << std::setfill('-') << std::setw(10) << num << std::endl;

    

    return 0;
}
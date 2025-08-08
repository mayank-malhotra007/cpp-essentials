
#include<iostream>
#include<iomanip>

// (base10)-> default

int main()
{

    int num = 255;
    int num2 = -255;
    
    std::cout << num << std::endl;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num <<std::endl;
    std::cout << std::oct << num <<std::endl;

    // using showbase
    std::cout << "after showbase" << std::endl;

    std::cout << std::showbase;
    std::cout << num << std::endl; // the last setting of octal persists
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num <<std::endl;
    std::cout << std::oct << num <<std::endl;

    // using uppercase
    std::cout << "after uppercase" << std::endl;
    std::cout << std::uppercase;

    std::cout << num << std::endl;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num <<std::endl;
    std::cout << std::oct << num <<std::endl;

    // using showpos
    std::cout << "after showpos" << std::endl;

    std::cout << std::showpos;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num <<std::endl;
    std::cout << std::oct << num <<std::endl;
    std::cout << std::dec << num2 << std::endl;
    std::cout << std::hex << num2 <<std::endl;
    std::cout << std::oct << num2 <<std::endl;

    // resetting
    std::cout << "after resetting to defaults" << std::endl;

    std::cout << std::noshowpos;
    std::cout << std::nouppercase;
    std::cout << std::noshowbase;

    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num <<std::endl;
    std::cout << std::oct << num <<std::endl;
    std::cout << std::dec << num2 << std::endl;
    std::cout << std::hex << num2 <<std::endl;
    std::cout << std::oct << num2 <<std::endl;


    // using setf method
    std::cout << "after using setf method" << std::endl;

    std::cout.setf(std::ios::showbase);
    std::cout.setf(std::ios::showpos);
    std::cout.setf(std::ios::uppercase);

    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num <<std::endl;
    std::cout << std::oct << num <<std::endl;
    std::cout << std::dec << num2 << std::endl;
    std::cout << std::hex << num2 <<std::endl;
    std::cout << std::oct << num2 <<std::endl;


    // unset using resetiosflags

    std::cout << "after resetting" << std::endl;

    std::cout << std::resetiosflags(std::ios::showbase);
    std::cout << std::resetiosflags(std::ios::showpos);
    std::cout << std::resetiosflags(std::ios::uppercase);

    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num <<std::endl;
    std::cout << std::oct << num <<std::endl;
    std::cout << std::dec << num2 << std::endl;
    std::cout << std::hex << num2 <<std::endl;
    std::cout << std::oct << num2 <<std::endl;

    return 0;

}
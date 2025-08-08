
#include<iostream>
#include<iomanip>

int main()
{


    double num1 = 12346.789122;
    double num2 = 123456789;
    double num3 = 1234.0;

    // NOTE: by default precision is 6
    // default
    std::cout << "defaults" << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;


    // SETPRECISION
    std::cout << "after precision to 3" << std::endl;
    std::cout << std::setprecision(3);
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    // using setprecision
    std::cout << "after precision to 5" << std::endl;
    std::cout << std::setprecision(5);
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;


     // using setprecision
    std::cout << "after precision to 7" << std::endl;
    std::cout << std::setprecision(7);
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    // using setprecision
    std::cout << "after precision to 2" << std::endl;
    std::cout << std::setprecision(2);
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    // NOTE: last precision setting persists
    // default
    std::cout << "defaults" << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;


    // FIXED
    std::cout << "after setting precision to 3 and fixed" << std::endl;
    std::cout << std::setprecision(3) << std::fixed;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;


    std::cout << "after setting precision to 5 and fixed" << std::endl;
    std::cout << std::setprecision(5) << std::fixed;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;


    // SCIENTIFIC
    std::cout << "after using scientific" << std::endl;
    std::cout << std::scientific;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;


    // using setprecision and scientific
    std::cout << "after using setprecision and scientific" << std::endl;
    std::cout << std::setprecision(7) <<std::scientific;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    // DEFAULT FLOAT
    std::cout << "using defaultfloat" << std::endl;
    std::cout << std::defaultfloat;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;


    // DEFAULT
    std::cout << "defaults" << std::endl;
    std::cout << std::resetiosflags(std::ios::fixed);
    std::cout << std::resetiosflags(std::ios::scientific);
    std::cout << std::setprecision(6);

    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

     // DEFAULTFLOAT
    std::cout << "using defaultfloat" << std::endl;
    std::cout << std::defaultfloat;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    return 0;


}
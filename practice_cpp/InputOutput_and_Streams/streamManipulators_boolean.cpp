
#include<iostream>
#include<iomanip>


int main()
{

    std::cout <<(10==10) << std::endl;
    std::cout << (10==20) << std::endl;

    // using the boolAlpha
    std::cout << std::boolalpha; // set the std::cout , setting will persist

    std::cout << (10==10) << std::endl;
    std::cout << (10==20) << std::endl;

    // testing default
    std::cout <<(10==10) << std::endl;
    std::cout << (10==20) << std::endl;
 
    // setting to default
    std::cout << std::noboolalpha;
    std::cout << (10==10) << std::endl;
    std::cout << (10==20) << std::endl;

    // using the setf method , the setting will persist
    std::cout.setf(std::ios::boolalpha);
    std::cout << (10==10) << std::endl;
    std::cout << (10==20) << std::endl;

    // testing default
    std::cout <<(10==10) << std::endl;
    std::cout << (10==20) << std::endl;


    // unset the any method to default
    std::cout << std::resetiosflags(std::ios::boolalpha);
    std::cout <<(10==10) << std::endl;
    std::cout << (10==20) << std::endl;




    return 0;
}
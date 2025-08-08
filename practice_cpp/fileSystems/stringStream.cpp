
#include<iostream>
#include<sstream>


int main()
{

    int num=10;
    double total=12.56;
    std::string name {"david"};

    std::string info {"Moe 100 1234.5"};

    // reading from a stream object
    std::istringstream iss {info};
    iss>>name>>num>>total; // reading data from the string info via iss
    std::cout << iss.str() << std::endl;

    //writing to a stream object
   
    std::ostringstream sti;

    sti << num << " " << total << " " << name ;
    std::cout << sti.str() << std::endl;
    
    std::string employee=sti.str();
    std::cout << employee << std::endl;


    return 0;
}
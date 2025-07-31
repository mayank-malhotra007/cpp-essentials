
// Exception Handling //

#include <iostream>


int main()
{
    double average;
    int sum, total;

    std::cout << "enter sum: ";
    std::cin>>sum;

    std::cout << "enter total: ";
    std::cin >> total;

    try {
        if(total == 0)
        {
            throw 0;
        }
        else
        {
            average = sum / total;
            std::cout << "Average: " << average << std::endl;
        }
    }
    
    catch(int ex)
    {
        std::cerr << "cant divide by 0" << std::endl;
    }

    return 0;
}
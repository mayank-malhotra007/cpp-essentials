#include <iostream>

int main()
{
    const int size=5;
    int numbers[size] {1,2,3,4,5};

    for(int i=0; i<size; i++)
    {
        std::cout << numbers[i] << " ";
    }

    // reverse
    
    int* start=&numbers[0];
    int* end=&numbers[size-1];
    int temp=0;
    std::cout << "temp: " << temp << std::endl;
    while(start<end)
    {
        int temp=*start;
        *start=*end;
        *end=temp;

        start++;
        end--;
    }
    std::cout<<std::endl;
    //print
    for(int i=0; i<size; i++)
    {
        std::cout << numbers[i] << " ";
    }

    std::cout<<std::endl;
    return 0;
}
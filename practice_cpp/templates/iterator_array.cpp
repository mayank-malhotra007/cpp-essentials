
/*
ITERATORS and std::array

*/


#include<iostream>
#include<array>

int main()
{

    std::array<int,5> numbers {1,2,3,4,5};
    std::array<int,5>::iterator i;

    i = numbers.begin();

    while(i!=numbers.end())
    {
        std::cout<<*i<<" ";
        i++;
    }

    std::cout<<std::endl;

    for(auto x= numbers.begin(); x<=numbers.end()-1; x++)
    {
        std::cout<<*x<<" ";

    }

    // reverse iterator
    std::cout<<std::endl;

    std::array<int,5>::reverse_iterator j;

    j = numbers.rbegin();

    while(j!=numbers.rend())
    {
        std::cout<<*j<<" ";

        j++;
    }
    
    


    return 0;
}
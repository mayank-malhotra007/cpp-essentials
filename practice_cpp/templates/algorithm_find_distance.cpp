
#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
    std::vector<int> numbers {1,2,2,100,4,5};

    // find if the element is present in the vector
    auto x = std::find(numbers.begin(), numbers.end(), 100);
    
    if(x!=numbers.end())
    {
     std::cout<<" element "<<*x<<" found "<<std::endl;
    }else{
        std::cout<<"element not found"<<std::endl;
    }

    // get the index of the number

    auto first=numbers.begin();

    /*
        std::distance(first,last) returns number of steps from first to last, it returns type long
    */

    auto index=std::distance(first, x);
    std::cout<<index<< std::endl;

    return 0;
}
/*
 DEQUE
*/

#include<iostream>
#include<deque>
#include<algorithm>
#include<ranges>
#include<vector>

// only if T is iterable, then this display runs
template <std::ranges::range T>
void display(const T& obj) 
{

    if(!obj.empty())
    {
        for(auto& i : obj)
        {
            std::cout<<i<<" ";

        }
    }
    else
    {
        std::cout<<"empty container"<<std::endl;
    }

    std::cout<<std::endl;

}//end display





int main()
{

    std::deque<int> d {1,2,3};
    std::deque<int> d1;
    std::deque<int> d2 {0,0,0};
    std::deque<int> d3;

    display(d);
    display(d1);

    // push
    d2.push_back(10);
    d2.push_back(20);

    d2.push_front(100);
    d2.push_front(200);

    display(d2);

    // pop
    d2.pop_back();
    d2.pop_front();

    display(d2);

    //push even numbers at back of the deque
    for(int i=1; i<=10;i++)
    {
        if(i%2==0)
        {
            d2.push_back(i);
        }
    }
    display(d2);

    std::vector<int> v {1,2,3,4,5,6,7,8,9,10};
    std::copy_if(v.begin(), v.end(),std::back_inserter(d3), [](int x){return x%2==0;} );
    // or std::transform(v.begin(), v.end(),std::back_inserter(d3), [](int x){return x%2==0?x:0;} );
    display(d3);
    
    
    return 0;
}




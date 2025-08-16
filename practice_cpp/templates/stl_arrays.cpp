
/*

Demonstrates the use of std::array, iterators and some algorithms associated with std::arrays.

*/


#include<iostream>
#include<array>
#include<algorithm>
#include<numeric>


void display(std::array<int,5>& x)
{ 
    //range based for loop
    for(int i :x)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}


bool findEven(int x)
{
    return x%2==0;
}


int main()
{
    std::array<int,5> a1{1,2,3,4,5};
    std::array<int,5> a2;
    std::array<int,5> a3;
    std::array<int,5> a4 {100,7,7,2,3};

    display(a1);
    std::cout<<std::endl;
    display(a2);
    std::cout<<std::endl;

    a2={10,11,12,13,14};
    display(a2);
    std::cout<<std::endl;

    // using front and back
    std::cout<<a1.front()<<std::endl;
    std::cout<<a1.back()<<std::endl;

    // do a bounds check
    std::cout<<"bounds check..."<<std::endl;

    std::cout<<a1[6]<<std::endl;

    try{
        std::cout<<a1.at(6)<<std::endl;
        throw 0;
    }catch(std::exception& ex)
    {
        std::cout<<"bound exceeded"<<std::endl;
    }


    // using fill method

    a3.fill(0);
    std::cout<<"a3: ";
    display(a3);


    // using swap method

    a1.swap(a2);
    display(a1);
    display(a2);

    // getting the raw pointer

    int* ptr = a1.data(); // returns address of first element of array
    std::cout<<*ptr<<std::endl;
    ptr++;
    std::cout<<*ptr<<std::endl;

    // using SORT algorithm

    std::sort(a4.begin(), a4.end());
    display(a4);

    // using MIN_ELEMENT and MAX_ELEMENT algorithm

    auto it = std::min_element(a1.begin(), a1.end()); // returns an iterator(a pointer) to the min_element
    std::cout<<it<<std::endl;
    std::cout<<*it<<std::endl;
    
    std::array<int,5>::iterator it2 = std::max_element(a1.begin(), a1.end()); // returns an iterator to the min_element
    std::cout<<it2<<std::endl;
    std::cout<<*it2<<std::endl;

    // using adjacent_find from #include<algorithm>

    auto adj = std::adjacent_find(a4.begin(), a4.end());
    std::cout<<"adjacent element: "<<*adj<<std::endl;

    // using accumulate from #include<numeric>
    int sum=0;
    sum = std::accumulate(a2.begin(), a2.end(),0); // start adding from 0
    std::cout<<"sum: "<<sum<<std::endl;


    // using count algorithm
    std::array<int,5> a5 {1,1,1,3,3};

    int count=std::count(a5.begin(), a5.end(),1);
    std::cout<<"count: "<<count<<std::endl;

    // using count_if algorithm with lambda, count_if(itr1, itr2, bool)

    std::array<int,5> a6 {2,2,4,1,3};
    int c = std::count_if(a6.begin(), a6.end(), [](int x){return x%2==0;});
    std::cout<<"c: "<<c<<std::endl;

    // using count_if with function
    int d = std::count_if(a6.begin(), a6.end(), findEven);
    std::cout<<"d: "<<d<<std::endl;

    return 0;
}

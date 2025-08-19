/*
Lists

-> a bidirectional linked list
-> do support random access, using [] or at()
-> efficiently insert or remove elements anywhere in the list

Foward Lists

-> a single linked list, only go forward
-> does not support reverse iterators, cant traverse back
-> cant use std::reverse in forward_lists use .reverse() member function

*/



#include<iostream>
#include<list>
#include<forward_list>
#include<ranges>
#include<algorithm>



template <std::ranges::range T>
void display(const T& obj)
{
    // range based for loop
    for(auto& i:obj)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}


// using a while loop
template <typename T>
void display2(const T& obj)
{
    auto it = obj.begin();
    while(it!=obj.end())
    {
        std::cout<<*it<<" ";
        it++;
    }
    std::cout<<std::endl;
}


// for reverse display
template <typename T1>
void display3(const T1& obj)
{
    auto rev_it = obj.rbegin();
    while(rev_it != obj.rend())
    {
        std::cout<<*rev_it<<" ";
        rev_it++;
    }
    std::cout<<std::endl;

}


int main() {

    std::list<int> l1 {1,2,3};
    std::list<int> l3{100,200,300,400,500};

    std::cout<<l1.size()<<std::endl;

    // push methods
    l1.push_back(4);
    l1.push_front(0);

    
    std::cout<<l1.size()<<std::endl;
    display(l1);
    
    // find and insert method
    auto it = std::find(l1.begin(), l1.end(), 3);
    if(it!=l1.end())
    {
        l1.insert(it,10);
    }

    display(l1);
 
    // resize method
    l1.resize(2);
    display(l1);
    l1.resize(5);
    display(l1);

    // reverse iterator
    display3(l1);

    // reverse() method works with arrays, vectors, lists as they can be traversed either ways

    std::reverse(l3.begin(), l3.end());
    std::cout<<"after reverse method: "<<std::endl;
    display(l3);


    
    //----------------------------------- Forward List-------------------------------------//

    std::forward_list<int> l2;
    l2.push_front(1);
    l2.push_front(2);
    l2.push_front(3);
    display(l2);

    // find and insert_after method
    auto it2 = std::find(l2.begin(), l2.end(), 2);
    if(it2!=l2.end())
    {
        l2.insert_after(it2,100);
    }

    display2(l2);
    //.reverse() member function used
    l2.reverse();
    display(l2);

    


    return 0;
}



/*
    Adaptive Container, meaning it can implement a vector, list, array, deque underneath it
    STACK (LIFO - last in first out)
    Does not support iterators, hence no algorithms
    By default deque implemented as a container
*/


#include<iostream>
#include<stack>
#include<vector>
#include<list>


template <typename T>
void display(std::stack<T> s) // attention, we are catching by value so a copy is created!
{
    
    while(!s.empty())
    {
        T elem=s.top();
        s.pop();
        std::cout<<elem<<std::endl;

    }
}


int main(){

    std::stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);

    display(s1);
    
    std::stack<int> s2;
    for(int i:{1,2,3,4,5})
    {
        s2.push(i);
    }

    display(s2);

    std::cout<<"stack s2 size: "<<s2.size()<<std::endl;

    s2.top()=6;
    display(s2);



    return 0;
}
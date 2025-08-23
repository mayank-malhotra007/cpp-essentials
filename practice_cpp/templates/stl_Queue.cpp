/*
    Adaptive container, means it can implement a list or deque underneath it.
    QUEUE (FIFO-first in first out)
    Operations on both ends
    Iterators not supported, hence no algorithms
    By default deque implemented as a container

*/

#include<iostream>
#include<queue>


template <typename T>
void display(std::queue<T> A) {
    while(!A.empty())
    {
        int x = A.front();
        A.pop();
        std::cout<<x << " ";
    }
    std::cout<<std::endl;
}




int main()
{

    std::queue<int> q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);

    std::cout<<q1.front()<<std::endl;
    std::cout<<q1.back()<<std::endl;
    std::cout<<q1.size()<<std::endl;

    std::queue<int> q2;
    for(int i: {10,20,30,40,50})
    {
        q2.push(i);
    }
    display(q2);

    return 0;
}
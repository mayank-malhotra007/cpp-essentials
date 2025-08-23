
/*
Priority Queue are also adaptive containers, by default vector container is implemented underneath instead of a deque.
PQ use heap data structure to store elements.
The element with highest prio is stored at the top.
No iterators, hence no algorithms

-> does not have .front() and .back() methods!

*/


#include<iostream>
#include<queue>

// printed in order, largest to smallest
void display(std::priority_queue<int> p)
{
    while(!p.empty())
    {
        int x = p.top();
        std::cout<<x<<" ";
        p.pop();
    }
    std::cout<<std::endl;
}



int main()
{

    std::priority_queue<int> pq;

    for(int i:{10,20,1,2,100,200,1000})
    {
        pq.push(i);
    }

    std::cout<<pq.top()<<std::endl; // gives the largest element
    std::cout<<pq.size()<<std::endl;
    display(pq);
    


    return 0;
}
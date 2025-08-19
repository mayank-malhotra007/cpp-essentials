
/*

DEQUE: double ended queue

-> direct element access (constant time)
-> inserstion both front and back (constant time)
-> insertion in middle (linear time)
-> all iterators available and may invaliadte
-> elements not stores in contimous memory locations

*/


#include<iostream>
#include<deque>


int main()
{
    std::deque<int> d {1,2,3};

    d.push_back(4);
    d.push_front(0);

    std::cout<<d.size()<<std::endl;
    std::cout<<d.max_size()<<std::endl;

    std::cout<<d[0]<<std::endl;
    std::cout<<d[10]<<std::endl;
    
    try{
        std::cout<<d.at(10)<<std::endl;
        throw 0;
    }catch(std::exception& ex)
    {
        std::cerr<<"out of bounds"<<std::endl;
    }
    

    std::deque<int>:: iterator it = d.begin();


    while(it!=d.end())
    {
        std::cout<<*it<<" ";
        it++;
    }
    std::cout<<std::endl;
    return 0;
}

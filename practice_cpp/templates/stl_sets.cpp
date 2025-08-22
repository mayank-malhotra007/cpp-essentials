/*
    SETS
    set, multiset, unorderedSet, unorderedMultiSet
    SET: unique elements
    no front & back methods
    no random access, no at() opeartor

    SETS are implemented as red-black trees, and use the compare algo to sort.
*/



#include<iostream>
#include<set>


int main()
{
    std::set<int> s1 {1,2,3,3,5,7,6};
    auto p1 = s1.insert(8); // returns a std::pair<> object
    s1.insert(7);

    auto it = s1.begin();
    while(it!=s1.end())
    {
        std::cout<<*it<<" ";
        it++;
    }

   //auto it2 = p1.first;

   bool result = p1.second;
   
   std::cout<<std::endl;
   std::cout<<"result: "<<result<<std::endl;

   std::cout<<std::endl;

    // removes an element from the SET
    s1.erase(7);
    
    auto it3 = s1.begin();
    while(it3!=s1.end())
    {
        std::cout<<*it3<<" ";
        it3++;
    }

    // use the FIND method
    std::cout<<std::endl;
    auto f = s1.find(3);
    std::cout<<"Found: "<<*f<<std::endl;
    std::cout<<std::endl;
    if(f!=s1.end())
    {
        std::cout<<"iterator valid"<<std::endl;
    }else{
        std::cout<<"iterator invalid"<<std::endl;
    }
    
    std::cout<<std::endl;
    // COUNT method
    std::cout<<"count of element 5: "<<s1.count(5)<<std::endl;

    // EMPTY method to check if set is empty
    std::cout<<"set status: "<<s1.empty()<<std::endl;
    
    if(s1.empty())
    {
        std::cout<<"set is empty"<<std::endl;
    }else{
        std::cout<<"set is not empty"<<std::endl;
    }
   
   
   
    std::cout<<std::endl;
    return 0;
}
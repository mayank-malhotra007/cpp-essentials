
/*
    MAPS, UNORDERED_MAP, MULTI_MAP , UNORDERED_MULTI_MAP

    -> Maps
    Need? When the user wants to associate keys with values. They are like dictionaries.
    Like sets, maps are implemented as red-black trees, therefore, insertions, deletions, lookups are faster comapred to lists.
    Logarithmic time.
    Maps insertions are ordered.
    Sorting is done using keys.
    No duplicate keys.
    Maps use std::pair<> objects

    -> Unorderd_maps are even faster, as they dont sort.
    Constant time access.
    Does not sort.

    -> Multimap allow duplicates, soring based on keys.

    -> Unordered Multimap, allow duplicates but do not sort.


    

*/

#include<iostream>
#include<map>


int main()
{

    std::map<std::string, int> m1 {{"Larry", 10}};

    // accessing an element
    std::cout<<m1["Larry"];

    // insertion into a map

    m1["Dodo"] = 20;
    std::cout<<std::endl;
    std::cout<<m1["Dodo"]<<std::endl;

    std::cout<<"Size: "<<m1.size()<<std::endl;

    // updating the value at a key

    m1["Dodo"] = 30;
    std::cout<<m1["Dodo"]<<std::endl;

    // find member method
    auto it  = m1.find("Larry");
    if(it!=m1.end())
    {
        std::cout<<"found Larry";
    }else{
        std::cout<<"not found";
    }
    std::cout<<std::endl;


    // erase member method
    m1.erase("Dodo");
    auto it2 = m1.find("Dodo");
    if(it2!=m1.end())
    {
        std::cout<<"found Dodo"<<std::endl;
    }else{
        std::cout<<"not found Dodo"<<std::endl;
    }
    

    return 0;
}




#include<iostream>
#include<set>

int main(){

    std::set<char> s {'C', 'H', 'A', 'B', 'C'};
    auto it = s.begin();
    // std::set<char> :: iterator it;
    while(it!=s.end())
    {
       std::cout<<*it<<" ";
       it++;
    }


    

    return 0;
}
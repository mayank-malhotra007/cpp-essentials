
#include <iostream>

int main() {
    
    std::vector<int> num = {10,2,3};
    std::vector<std::string> name = {"mayank", "malhotra"};

    std::vector<int>* p1;
    std::vector<std::string>* p2;

    p1 = &num;
    p2 = &name;

    //if(p1==p2) {std::cout << "equal" << std::endl;} // cant compare different dataTypes
    //else{std::cout << "not equal" << std::endl;}
   
    std::vector<int> keys = {10,20,30};
    std::vector<int>* p3;
    p3 = &keys;

    if(p1==p3) // can compare pointers pointing to same datatype
        std::cout << "equal" << std::endl;
    else
        std::cout << "unequal" << std::endl;

    // iteration    
    for(int i=0; i<num.size(); i++)
    {
        std::cout << (p1+i) << std::endl;
    }
    
    int i = 0;
    while (i < p1->size())
    {
        std::cout << "address:" <<(p1+i) << std::endl;
        i++;
    }

    std::vector<int>* p4;
    p4 = &num;

    if(p1==p4) // point to the same vector
        std::cout << "equal" << std::endl;
    else
        std::cout << "not equal" << std::endl;

    for(int i: *p1)
    {
        for(int j: *p3)
        {
            if(i==j)
            {
                std::cout << "equal: " << i << std::endl;
            }
        }
    }

    

    return 0;
}
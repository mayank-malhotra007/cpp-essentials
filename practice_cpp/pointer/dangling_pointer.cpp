
#include <iostream>

int main() {

    int* ptr1 = new int(10);
    int* ptr2;

    ptr2 = ptr1;

    std::cout<< " p1 has: " << *ptr1 << " p2 has: " << *ptr2 << std::endl;
    
    delete ptr1;

    // ptr2 becomes a dangling pointer to the heap mem
    //std::cout<< "p1 has: " << *ptr1 << "p2 has: " << *ptr2 << std::endl;

    delete ptr2;
   
    //std::cout<< "p1 has: " << *ptr1 << "p2 has: " << *ptr2 << std::endl;

    ptr1 = nullptr;
    ptr2 = nullptr;

    std::cout << "after setting both to null" << std::endl;
    std::cout<< "p1 has: " << *ptr1 << "p2 has: " << *ptr2 << std::endl;

}
// Resource Acquisition is Initialization -> happens via constructor

// points to object of type T on the heap
// there can only be one unique pointer to the object
// owns what it points to
// cannot be assigned, cannot be copied
// can be moved
// when the ptr is destroyed, what it points to is destroyed


#include <iostream>
#include <memory>

int main() {

    std::unique_ptr<int> p1 { new int {100} };
    std::unique_ptr<int> p2 = std::make_unique<int>(1000); // after C++14
    auto p3 = std::make_unique<int>(2000);  // using auto keyword

    std::cout << *p1 << std::endl;
    std::cout << p1.get() << std::endl; // gets the address



    p1.reset(); // set to nullptr
    

    return 0;
}


// Resource Acquisition is Initialization -> happens via constructor //

// 1.points to object of type T on the heap
// 2.there can only be one unique pointer to the object
// 3.owns what it points to
// 4.cannot be assigned, cannot be copied
// 5.can be moved
// 6.when the ptr is destroyed, what it points to is destroyed


#include <iostream>
#include <memory>

int main() {

    std::unique_ptr<int> p1 { new int {100} };
    std::unique_ptr<int> p2 = std::make_unique<int>(1000); // after C++14
    auto p3 = std::make_unique<int>(2000);  // using auto keyword

    std::cout << *p1 << std::endl;
    std::cout << p1.get() << std::endl; // gets the address
   
    p3 = std::move(p1); // we move the ownership to p3 pointer, sets p1 to nullptr
    

    //p1.reset(); // set to nullptr
    
    std::cout << *p3 << std::endl;

    p2.reset();
    p3.reset();

    return 0;
}


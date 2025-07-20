
// 1. provides shared ownership, heap object can be shared by multiple pointers
// 2. can copy, can move, can assign
// 3. when use count is 0, then the object on heap is destroyed

// Why need a shared pointer? -> multiple parts of your program that need to share ownership of the same resource

#include <iostream>
#include <memory>

int main() {

    std::shared_ptr<int> p1 {new int (100)};
    std::shared_ptr<int> p2 {p1};
    std::shared_ptr<int> p3;
    p3 = p1;   // assign

    std::cout << *p1 << " " << *p2 << std::endl;

    std::cout << p1.use_count() << std::endl;
    std::cout << p2.use_count() << std::endl;
  
    p1.reset();
    std::cout << p1.use_count() << std::endl;
    std::cout << p2.use_count() << std::endl;
  
    return 0;
}
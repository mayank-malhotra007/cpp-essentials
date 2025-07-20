
// Weak pointers are created from shared pointers.
// Why do we need weak pointers? -> it observes a shared ptr wihtout increasing its reference count.
// Used in circular reference structures or trees.
// Check if the shared pointer is alive.



#include <iostream>
#include <memory>


int main() {

    std::shared_ptr<int> p1 = std::make_shared<int>(100);
    std::weak_ptr<int> p2 = p1;

    if(auto temp = p2.lock())
    {
        std::cout << "p1 exists" << std::endl;
    }

    p1.reset(); // sets p1 to nullptr

    if(auto temp = p2.lock())
    {
        std::cout << "p1 exists" << std::endl;
    }
    else
    {
        std::cout << "p1 destroyed" << std::endl;
    }





    return 0;
}


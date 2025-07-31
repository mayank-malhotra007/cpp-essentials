
// Program shows that objects of both Engine and Car did not form properly //

#include <iostream>
#include <stdexcept>

class Engine {

    public:
    Engine() 
    {
        throw std::runtime_error("engine failure");
        // throw std::runtime_error("engine failure"); // duplicate, removed
        std::cout << "engine started.." << std::endl;
    }

    ~Engine(){std::cout << "destructor engine";}
};


class Car {
    public:
    Car() try{
        Engine e;
        std::cout << "car assembled" << std::endl;
    } catch(const std::exception& ex)
    {
        std::cout<<"caught" << std::endl;
    }

    ~Car(){std::cout << "destructor car" << std::endl;}
};


int main() {

    Car obj;

    return 0;
}



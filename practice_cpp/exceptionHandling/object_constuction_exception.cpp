

#include <iostream>


class Risky {

    public:
    Risky() {
        std::cout << "risky constructor" << std::endl;
        throw std::runtime_error("failed");
    }

    ~Risky(){std::cout << "risky destructor called" << std::endl;}
};


int main(){

    try
    {
        Risky R;
    }catch(const std::exception& e)
    {
        std::cout << "handled in main" << std::endl;
    }

    

    return 0;
}
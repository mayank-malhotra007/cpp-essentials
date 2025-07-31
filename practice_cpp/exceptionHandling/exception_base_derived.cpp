
#include <iostream>

class Base {


    public:
    Base(){std::cout << "base constructor" << std::endl;}
    virtual void process()
    {
        throw std::runtime_error("base failed");
    }

    virtual ~Base(){std::cout << "base destructor called" << std::endl;}
};



class Derived : public Base {

    public:
    Derived(){std::cout << "derive constructor" << std::endl;}
    void process() override
    {
        try
        {
            Base::process(); 
        } catch(const std::exception& ex)
        {
            std::cout << "handled in derive" << std::endl;
        }
    }

    ~Derived(){std::cout << "derive destructor called" << std::endl;}
};

int main()
{
    //Derived d_obj;
    //d_obj.process();

    //Base b;
    //b.process();

    Base* b_ptr = new Derived();
    b_ptr->process();

    delete b_ptr;

    return 0;
}
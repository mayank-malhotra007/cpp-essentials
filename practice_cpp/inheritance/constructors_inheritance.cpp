
// Constructors and Inheritance //


#include <iostream>




class Base {



    int num=0;


    public:
    // default
    Base(){std::cout << "base class constructor" << std::endl;}
    // 1 arg constructor

    Base(int x): num(x) {    
        std::cout <<"x initialized" << std::endl;
    } 

    // copy constructor
    Base(const Base& rhs) {
        std::cout << "copy  base constructor called" << std::endl;
        num = rhs.num;
    }

    // move constructor
    Base(Base&& rhs) noexcept: num(rhs.num)
    {
        std::cout << "move base constructor called" << std::endl;
        rhs.num = 0;
    }

    // assignment operator
    Base& operator=(const Base& rhs){
        std::cout << "assignment op from base called" << std::endl;
        if(this==&rhs)
            return *this;

        num=rhs.num;
        return *this;
    }
    
};




class Derived : public Base {

    int amount=0;
   
    public:
    //default
    Derived(){std::cout << "derived construcor" << std::endl;}


    Derived(int x): Base(x), amount(x)
    {
        std::cout << "derived construcor with 1 arg, amount = " << amount << std::endl;
    }

    Derived(const Derived& rhs) : Base(rhs)
    {
        std::cout << "derived class copy constructor called" << std::endl;
    }

    Derived(Derived&& rhs) noexcept : Base(std::move(rhs)), amount(rhs.amount)
    {
        std::cout << "derived class move constructor called" << std::endl;
        rhs.amount=0;
    }


    Derived& operator=(const Derived& rhs) 
    {
        std::cout << "assignment op from derived called" << std::endl;
        if(this==&rhs)
            return *this;

        Base::operator=(rhs);

        amount=rhs.amount;
        
        return *this;
        
    }


};




int main() {

    std::unique_ptr<Base> base_ptr = std::make_unique<Base>(); 

    std::unique_ptr<Derived> derived_ptr1 = std::make_unique<Derived>();

    std::unique_ptr<Derived> derived_ptr2 = std::make_unique<Derived>(100);

     
    Derived d_obj1;           // defaults
    Derived d_obj2 {d_obj1};  // copy
    Derived d_obj3 {std::move(d_obj2)}; // move         

    d_obj3 = d_obj1;    // assignment op = is called

    return 0;
}
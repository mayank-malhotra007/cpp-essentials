
#include <iostream>
#include <memory>

class B;

class A {

    std::shared_ptr<B> b_ptr;
        
    public:
        void set_B(std::shared_ptr<B> &b)
        {
            b_ptr = b;
        }

        A() { std::cout << "A constructor\n"; }
        ~A() { std::cout << "A destructor\n"; }

};






class B {

    std::weak_ptr<A> a_ptr;

    public:
        void set_A(std::shared_ptr<A> &a)
        {
            a_ptr = a;
        }

        void use_A() {
            if(auto sharedA = a_ptr.lock())
            {
                std::cout << "Using A safely" << std::endl;
            }
            else
            {
                std::cout << "A has been destroyed" << std::endl;
            }
        }



        B() {std::cout << "B constructor" << std::endl; }
        ~B() {std::cout << "B destructor" << std::endl;}


};

int main() {

    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    
    b->set_A(a);
    b->use_A();

    return 0;
}

#include <iostream>

class A {

    public:
        A(){std::cout << "constructor from class A " << std::endl;}
        void display()
        {
            std::cout <<"Hi Im from class A" << std::endl;
        }

        ~A(){std::cout << "destrucor from class A" << std::endl;}
};


class B : public A {

    public:
        B(){std::cout << "constructor from class B" << std::endl;}
        void display()
        {
            std::cout << "Hi Im from class B" << std::endl;
        }
        ~B(){std::cout << "destrucor from class B" << std::endl;}

};


class C : public B {

    public:

        C() try
        {
            std::cout << "constructor from class c" << std::endl;
            throw 0;
        } catch(int& ex)
        {
            std::cout << "caught in C" << std::endl;
         }

      
        void display()
        {
            std::cout << "Hi Im from class C" << std::endl;
        }
        ~C(){std::cout << "destructor from class c" << std::endl;}
};


int main(){

    try
    {
        C obj_c;
        obj_c.display(); // this never runs, because we throw in C constructor, object is never created.
    

    }

    catch(int& ex)
    {
        std::cout << "caught in main" << std::endl;
    }



    return 0;
}
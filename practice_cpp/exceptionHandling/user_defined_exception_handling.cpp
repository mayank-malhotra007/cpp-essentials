

#include <iostream>
#include <exception>


// the function what() returns a pointer to constant character data and does not change the object

class DivideByZeroException : public std::exception
{
    public:
    const char* what() const noexcept override{
        return "divide by zero exception";
    }
};


class NegativeValueException : public std::exception
{
      public:
    const char* what() const noexcept override{
        return "negative value exception";
    }
};



class Numbers
{
    

    public:
        Numbers(){std::cout << "default" <<std::endl;};
        

        void divide(int a, int b); // declare

    ~Numbers(){std::cout << "destructor called" << std::endl;}

};



void Numbers :: divide(int a, int b)
{

    if(a<0 || b <0)
    {
        throw NegativeValueException();
    }

    if(b==0)
    {
        throw DivideByZeroException();
    }

    else
    {
        std::cout << "result of divsion is: " << a/b << std::endl;
    }
}



int main()
{

    Numbers numObj1;


    try{
        numObj1.divide(10,0);
    }catch(const NegativeValueException& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    catch(const DivideByZeroException& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    return 0;

}



// Virtual function and Override //


#include<iostream>
#include<vector>

class Account{

    public:

    // NOTE: virtual keyword activates dynamic binding, polymorphism
     virtual void withdraw(int amount)
    {
        std::cout << "from account withdrawn: " << amount << std::endl;
    }

    virtual ~Account(){std::cout << "account destructor called" << std::endl;}
    // if we use virtual functions, make the destructor virtual as well, else it will only call base class destructor
};


class Savings : public Account{

    public:

     void withdraw (int amount) override
    {
        std::cout << "from savings withdrawn: " << amount << std::endl;
    }
    ~Savings(){std::cout << "savings destructor called" << std::endl;}
};


class Checking : public Account{

    public:

     void withdraw (int amount) override
    {
        std::cout << "from checking withdrawn: " << amount << std::endl;
    }

    ~Checking(){std::cout << "checkings destructor called" << std::endl;}
};


class Trust : public Savings {

    public:

     void withdraw (int amount) override
    {
        std::cout << "from trust withdrawn: " << amount << std::endl;
    }

    ~Trust(){std::cout << "trust destructor called" << std::endl;}
};


int main(){

    // static binding
    Account* p1 = new Account();
    Account* p2 = new Savings();
    Account* p3 = new Checking();
    Account* p4 = new Trust();


   /*
    Account* array_ptr[] = {p1,p2,p3,p4};
    size_t size = sizeof(array_ptr);
    
    std::cout << size << std::endl;

    for(int i=0; i<sizeof(array_ptr)/sizeof(p1); i++)
    {
        array_ptr[i]->withdraw(100);
    }
    */

    // vector of pointers to Account objects
    std::vector<Account*> ptrs = {p1, p2, p3, p4};
    std::cout << ptrs.size() << std::endl;
    //  a single pointer to a vector of account object
    //  std::vector<Account>* ptrs = p1

    std::cout << "printing using vectors" << std::endl;

    for(Account* acc_ptr : ptrs)
    {
        acc_ptr -> withdraw(100);
    }


    /*
    delete p1; 
    delete p2;
    delete p3;
    delete p4;
    */
    return 0;
}
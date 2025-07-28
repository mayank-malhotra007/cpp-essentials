

#include <iostream>



// ************  Accounts Class ********* //

class Account {

    friend std::ostream& operator<<(std::ostream& os, const Account& rhs);
    

    public:
    
    void deposit(double amount);
    void withdraw(double amount);

    ~Account(){std::cout << "destructor called account" << std::endl;}

};


std::ostream& operator<<(std::ostream& os, const Account& rhs)
{
    os << "rhs.amount" << std::endl;
    return os;
}


void Account :: deposit(double amount)
{
    std::cout << "deposit account amount: " << amount << std::endl;

}


void Account :: withdraw(double amount)
{

    std::cout << "withdraw account amount: " << amount << std::endl;

}



// ************  Savings Class ************ //

class Savings : public Account {


    friend std::ostream& operator<<(std::ostream& os, const Savings& rhs);

    
    public:
   

    void deposit(double amount);
    void withdraw(double amount);

    ~Savings(){std::cout << "destructor called savings" << std::endl;}

};

void Savings :: deposit(double amount)
{
    std::cout << "deposit savings amount: " << amount << std::endl;

}


void Savings :: withdraw(double amount)
{

    std::cout << "withdraw savings amount: " << amount << std::endl;

}

std::ostream& operator<<(std::ostream& os, const Savings& rhs)
{
    os << "rhs.amount" << std::endl;
    return os;
}


// *********** Main Class ********** //

int main(){

    Account a1;   // calls base constructor in base
    a1.deposit(1000);
    a1.withdraw(1000);


    Savings s1; // calls base constructor in account then savings
    s1.deposit(500);
    s1.withdraw(500);


    
    Account* ptr = new Savings(); // a ptr of return type is created from Savings class
    ptr -> deposit(999);   // prints account deposit!
    ptr -> withdraw(999);  // prints account withdraw!

    delete ptr;

    // NOTE: In C++, if a base class method is not marked virtual, calls to it are resolved using static binding — at compile time — based on the type of the pointer, not the actual object

    return 0;
}
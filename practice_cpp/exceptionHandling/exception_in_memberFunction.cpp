
#include <iostream>

class BankAccount {

    public:

    void withdraw(double amount)
    {
        try{
            if(amount>1000)
            {
                throw std::invalid_argument("withdrawl limit exceeded");
            }
            std::cout << "withdrawn: " << amount << std::endl;
        } catch(const std::exception& ex)
        {
            std::cout << "error" << std::endl;
        }
    }

    ~BankAccount(){std::cout << "destructor called" << std::endl;}
};

int main()
{
    BankAccount obj;
    obj.withdraw(1999);

    return 0;
}
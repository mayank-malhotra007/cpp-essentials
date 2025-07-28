
// Basic Example: Inheritance //

#include <iostream>


class Account{

    private:
        std::string secret_key = "secret";

    protected:

        int account_number=0;



    public:

    void deposit(double amount) {
        std::cout << "account deposit called with:" << amount << std::endl;

    }
    void withdraw(double amount){
        std::cout << "account withdraw called with:" << amount << std::endl;
    }


    void set_account_number(int acc)
    {
        account_number = acc;
        std::cout << "account number set to: " << acc << std::endl;
    }
  
    void access_key()
    {
        std::cout << "secret key is: " << secret_key << std::endl;
    }

    Account(){};
    ~Account(){};

};





class Savings_Account : public Account {

    public:
        Savings_Account(){};
        ~Savings_Account(){};


    
    void deposit(double amount) {
        std::cout << "savings deposit called with:" << amount << std::endl;


    }
    void withdraw(double amount){
        std::cout << "savings withdraw called with:" << amount << std::endl;
    }
    
    
};





int main(){


    Account obj_account;
    obj_account.deposit(1000);
    obj_account.withdraw(1000);
    //obj_account.account_number = 100;  // cant access protected member using object
    obj_account.set_account_number(123);
    obj_account.access_key(); // private member can only be accessed by a member function of the class itself;




    Savings_Account savings;
    savings.deposit(2000);    
    savings.withdraw(2000);
    savings.set_account_number(555);




    // using a smart pointer
    std::unique_ptr<Account> ptr =  std::make_unique<Account>();
    ptr->deposit(3000);
    ptr->withdraw(3000); 



    // using a raw pointer
    Savings_Account* ptr_s;  
    ptr_s = new Savings_Account();
    ptr_s -> deposit(4000);
    ptr_s -> withdraw(4000);
    ptr_s -> set_account_number(222);   
    ptr_s -> access_key(); // 

    delete ptr_s;



    return 0;
    

}

// Basic Example: Inheritance //

#include <iostream>


class Account{

    private:
        std::string secret_key = "secret";
        friend void revealSecret(const Account& s);
       

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
  
    void show_key()
    {
        std::cout << secret_key << std::endl;
    }

    Account(){};
    ~Account(){};

};



// NOTE: protected and public members of base class become protected in derived class, so not accessible via objects of derived class

class Savings_Account : protected Account {

    public:
        Savings_Account(){};
        ~Savings_Account(){};


    
    void deposit(double amount) {
        std::cout << "savings deposit called with:" << amount << std::endl;


    }
    void withdraw(double amount){
        std::cout << "savings withdraw called with:" << amount << std::endl;
    }
    
    void account_number_setter(int x)
    {
        set_account_number(x);
    }

  
    
};



void revealSecret(const Account& s)
{
    std::cout << "secret via friend: " << s.secret_key << std::endl;
}




int main(){


    Account obj_account;
    obj_account.deposit(1000);
    obj_account.withdraw(1000);
    //obj_account.account_number = 100;  // cant access protected member using object
    obj_account.set_account_number(123);
    obj_account.show_key();
  
    revealSecret(obj_account);



    Savings_Account savings;
    savings.deposit(2000);    
    savings.withdraw(2000);
    //savings.set_account_number(555);
    savings.account_number_setter(777);
    //savings.show_key(); // wont work as key is private 
 



    // using a smart pointer
    std::unique_ptr<Account> ptr =  std::make_unique<Account>();
    ptr->deposit(3000);
    ptr->withdraw(3000); 



    // using a raw pointer
    Savings_Account* ptr_s;  
    ptr_s = new Savings_Account();
    ptr_s -> deposit(4000);
    ptr_s -> withdraw(4000);
   //ptr_s -> set_account_number(222);   
   //ptr_s -> access_key(); // can still access secret_key as the member function is accessible




    delete ptr_s;


    return 0;
    

}
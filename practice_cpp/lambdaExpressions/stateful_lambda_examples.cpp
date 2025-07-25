
#include <iostream>
#include <algorithm>

int global_x(1000);  // cant capture a global variable!


void test1() {
    int local_x (10);
    std::cout << "Test1 executed..." << std::endl;

    // local_x is captured but as a const by value!
    auto l = [local_x](){
        
        std::cout << local_x << std::endl;
        std::cout << global_x << std::endl;
    };
    
    l(); // call the lambda


}


void test2() {

    std::cout << "Test2 executed ..." << std::endl;
    int x{100};
    
    auto lambda_1 = [x]()mutable{
        x = x+2000;
        std::cout << x << std::endl;
    };

    lambda_1();
    std::cout << x << std::endl; // x still stays the same,. we didnt capture by ref

    lambda_1(); // when we call again, it doesnt capture again, holds the previous value and adds
    std::cout << x << std::endl; 

    //NOTE: the constructor runs once and captures x, when l() is called the opeartor() is called.
}



void test3(){

    std::cout << "Test3 executed ... " << std::endl;

    int x {3000};

    auto lambda_2 = [&x]()mutable{
        x = x + 3000;
        std::cout << x << std::endl;
    };

    lambda_2();
    std::cout << x << std::endl; // value persists

} 


void test4() {

    std::cout << "Test4 executed ..." << std::endl;

    int a = 10;
    int b = 20;
    int c = 30;

   // '=' capture all by const value  
    auto lambda_3 = [=]()mutable{
        a = 110;
        b = 220;
        c = 330;

        std::cout << a << " " << b << " " << c << std::endl;

    };

    lambda_3();
    std::cout << a << " " << b << " " << c << std::endl;




}



void test5() {

    std::cout << "Test5 executed ..." << std::endl;
    
    int x {100};
    int y {200};
    int z {300};

    auto lambda_4 = [&](){
        x = x+100;
        y = y+100;
        z = z+100;

        std::cout << x << " " << y << " " << z << std::endl;

    }; 

    lambda_4();
    std::cout << x << " " << y << " " << z << std::endl;

    lambda_4(); // adds to the previous values

}


void test6(){

    std::cout << "Test6 executed ..." << std::endl;

    int x {100};
    int y {200};
    int z {300};

    auto l = [=,&y]()mutable{
        x+=10;
        y+=20;
        z+=30;

        std::cout << x << " " << y << " " << z << std::endl;
        
    };

    l();
    std::cout << x << " " << y << " " << z << std::endl; // y persists 

}

class Person{

    friend std::ostream& operator<<(std::ostream&, Person& rhs);

    std::string name;
    int age;

    public:
        Person() {std::cout << "default constructor" << std::endl;}

        Person(std::string name, int age): name{name}, age{age} {std::cout << "2 arg constructor" << std::endl;}

        // copy constructor
        Person(const Person& p){std::cout << "copy constructor" << std::endl;}


        // getters
        std::string get_name(){return name;}
        int get_age() {return age;}

        //setters
        void set_name(std::string name){this->name = name;}
        void set_age(int age){this->age = age;}


        auto func1() {
            return [this](std::string new_name, int new_age){name = new_name; age = new_age;};
        }

        
        auto func2() {
            return [=](std::string new_name, int new_age){name = new_name; age = new_age;};

        }
        

        auto func3() {
            return [&](std::string new_name, int new_age){name = new_name; age = new_age;};

        }



        ~Person(){std::cout << "destructor";}


};


std::ostream& operator<<(std::ostream& os, Person& rhs){

    std::cout << "Operator << overloaded" << std::endl;
    os << rhs.name << ":" << rhs.age << std::endl;
    return os;



}




void test7() {


    std::cout << "Test7 executed ..." << std::endl;

    Person person1("Larry", 18);
    std::cout << person1 << std::endl;

    auto lambda1 = person1.func1(); // returns the lambda
    lambda1("Moe", 30); // calls the lambda
    std::cout << person1 << std::endl;

    auto lambda2 = person1.func2(); // returns the lambda
    lambda2("Frank", 40); // calls the lambda
    std::cout << person1 << std::endl;


    auto lambda3 = person1.func3(); // returns the lambda
    lambda3("Gerald", 50); // calls the lambda
    std::cout << person1 << std::endl;




}

// what happens in the backgnd when a lambda expression runs

class Lambda {

    int y;
    public:
        Lambda(int y): y{y} {std::cout << "y initialized" << std::endl;}

        void operator()(int x) {
            std::cout << x+y << std::endl;
        }


};




void test9() {
    
    std::cout << std::endl;
    std::cout << "Test9 executed..." << std::endl;

    int y(100);

    Lambda l1(y); // const in class is called

    l1(500); // the operator() in class is called, x is passed

    auto l2 = [y](int x){std::cout << x+y << std::endl;};
    l2(1000); // lambda l2 is called, x is passed

}





int main() {


    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test9();
   

    return 0;
}
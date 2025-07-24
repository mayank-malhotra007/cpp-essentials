
#include <iostream>

class Person {

    friend std::ostream& operator<<(std::ostream& os, const Person& rhs);

    private:
        std::string name;
        int age;

    public:
        // 2 Arg constructor
        Person(std::string name, int age): name(name), age(age) {}
        // copy constructor
        Person(const Person& p): name(p.name), age(p.age) {}

        std::string get_name() const {return name;}

        void set_name(std::string name) {this->name = name;}

        int get_age() const{return age;}

        void set_age(int age) {this->age = age;}
};

std::ostream& operator<<(std::ostream& os, const Person& rhs){
    os << "Person: " << rhs.name << ":" << rhs.age << std::endl;
    return os;
}


void test1() {

    std::cout << "Test 1 executed.." << std::endl;

    [](){std::cout << "Hi" << std::endl;}();

    [](int x){std::cout << x << std::endl;}(100);

    [](int x, int y){std::cout << x << "," << y << std::endl;}(100,200);

}


void test2() {

    std::cout << "Test 2 executed..." << std::endl;

    auto l1 = [](){std::cout <<"Hi" << std::endl;};
    l1();

    int num1 = 100;
    int num2 = 200;

    auto l2 = [](int x, int y){std::cout << x+y << std::endl;};
    l2(10,20);
    l2(num1,num2);

    auto l3 = [](int& x, int y){std::cout << x <<"," << y << std::endl;
        x = 1000;
        y = 100;
    
    };
    l3(num1,num2);
    std::cout << "Num1: " << num1 << ", Num2: " << num2 << std::endl;

}


void test3() {

    std::cout << "Test3 executed..." << std::endl;

    Person stooge("Larry", 18);
    std::cout << stooge << std::endl; // over here the << op gets overloaded

    auto l4 = [](Person p){std::cout << p << std::endl;}; // copy const called, again << overloaded
    l4(stooge);


    auto l5 = [](const Person& p){std::cout << p << std::endl;}; // pass by ref no copy const
    l5(stooge);

    auto l6 = [](Person& p){
        p.set_name("Frank");
        p.set_age(25);
        std::cout << p << std::endl;
    };

    l6(stooge);

    std::cout << stooge << std::endl; // since last time stooge was passed as reference to l6


}



template<typename T, typename Func>
// here we have passed a lamda object to lambda
void filter_vector(T& vec, Func lambda)
{

    for(int i:vec)
    {
        if(lambda(i)) // func() calls the lamda, gives it an int , gets a bool in return, when its true, IF executes
        {
            std::cout << i << " ";
        }
    }
   

}






void test4() {

    std::cout << "Test4 executed..." << std::endl;

    std::vector<int> nums {10,20,30};

    filter_vector(nums, [](int x){return x>10;});
}



// this function returns a lambda object 
auto make_lambda() {
    return [](){std::cout << "hello" << std::endl;}; // only returns the lambda does not execute it.
} 



void test5() {
    std::cout << "Test5 executes..." << std::endl;
    auto l5 = make_lambda();

    l5(); // lambda runs here
}

void test6() {

    std::cout << "Test6 executed.." << std::endl;

    auto l6 = [](auto x, auto y){
        std::cout << x << y << std::endl;
    };

    l6(10,20);
    l6(100.12, 200.23);
    l6(Person("Larry",18), Person("Moe",20)); // << needs to be overloaded

}


void test7() {

    std::cout << "Test7 executes..." << std::endl;

    std::vector<Person> stooges {
        {"Moe", 20},
        {"Larry", 18},
        {"Curly", 16},
    };


    std::sort( begin(stooges), end(stooges), [](const Person& p1, const Person& p2){
        return p1.get_name() < p2.get_name();

    });

    std::for_each(begin(stooges), end(stooges), [](const Person& p)
    {
        std::cout << p << std::endl;
    });


    std::cout << "age based ..." << std::endl;

      std::sort( begin(stooges), end(stooges), [](const Person& p1, const Person& p2){
        return p1.get_age() < p2.get_age();

    });

     std::for_each(begin(stooges), end(stooges), [](const Person& p)
    {
        std::cout << p << std::endl;
    });



}





int main() {

    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
    //test6();
    test7();




    return 0;
}
// Lambdas are executed as inline functions and make the code smaller and faster!



#include<iostream>


class Multiplier {

    int num;

    public:
        Multiplier() {} // default constructor
        Multiplier(int n): num{n} {} // single arg constructor

        // functionc call operator aka Functors
        int operator()(int n) {
            return n*num;
        }



};

int main() {

    Multiplier mult(100); 

    std::vector<int> vec1 = {1,2,3,4,5};
    std::vector<std::string> vec2 = {"Munich", "Berlin", "Hamburg"};
    
    // std::for_each invokes the lambda

    std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x*x << std::endl;} );

    std::for_each(vec2.begin(), vec2.end(), [](std::string s){std::cout << s << std::endl;});

    std::transform(vec1.begin(), vec1.end(),vec1.begin(), mult); // here the functor is called
    std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x << std::endl;} );
    
    // iterating a vector without the lambda
    
    /*
    for(int i: vec1)
    {
        std::cout << i << std::endl;
    }
    */

    int x = 10;
    int y = 100;

    // self invoking lanbda
    int sum = [](int x, int y){return (x+y);}(x,y); // the parenthesis invoke the lambda
    std::cout << sum << std::endl;

    // return throws an object so auto is used instead of int
    auto sub = [](int x, int y){return (y-x);};
    std::cout << sub(200,300) << std::endl; 

    // simplest lambda , self invoking
    []()->std::string{std::cout << "Hi";}();

    return 0;
}
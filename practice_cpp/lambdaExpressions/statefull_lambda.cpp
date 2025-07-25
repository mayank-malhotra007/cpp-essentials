

#include <iostream>

int main() {


    int y {10};

    // variable y is caught as a const, default by const value
    auto l = [y](int x){
        // y=200; // cant change y as its const, just add keyword mutable before (int x)
        std::cout << x+y << std::endl;};
    l(100);


    auto m = [&y](int x) {
        y = 1000;
        std::cout << x+y << std::endl;
    };
    m(100);
    
    std::cout << y << std::endl;




    return 0;
}
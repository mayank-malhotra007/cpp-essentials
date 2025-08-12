
/*
FUNCTION TEMPLATES and generic programming
*/


#include<iostream>



template <typename T>
T square(T x)
{
    return x*x;
}


template <typename T>
T max(T x, T y)
{
  return x+y;
}


// return an expression from lambda
template <typename T1, typename T2>
auto add(T1 x, T2 y)
{   
    auto lambda = [](auto a, auto b){return a+b;};
    return lambda(x,y); // lambda called here
}


// return the lambda itself
template <typename T1, typename T2>
auto sub(T1 x, T2 y)
{
    return [](auto x, auto y){return x-y;};
}




int main()
{
    int x = 5;
    float y = 6.6;
    double z = 100.12;

    std::cout << square(x) << std::endl;
    std::cout << square(y) << std::endl;
    std::cout << square(z) << std::endl;

    std::cout << max(2,3) << std::endl;
    std::cout << max(3.4, 4.4) << std::endl;

   
    auto f=add(2.5,5);
    std::cout << f << std::endl;

    auto l = sub(6,5);
    std::cout << l(6,5) << std::endl;

    return 0;
}




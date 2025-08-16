
#include<iostream>
#include<vector>
#include<algorithm>

void square(int x){
    std::cout <<x*x<<" ";
}

int sum(int a, int b)
{
    return a+b;
}


int main()
{
    std::vector<int> numbers {1,2,3,4,5};
    long result=0;
    std::vector<int> x {10,20,30,40,50};
    std::vector<int> y {};

    std::for_each(numbers.begin(), numbers.end(), square);

    std::cout<<std::endl;

    std::for_each(numbers.begin(), numbers.end(), [](int x){std::cout << x*x<<" ";});
    
    auto l = std::for_each(numbers.begin(), numbers.end(), [&result](int x){
        std::cout<<x*x<<" ";
        result=x*x;
        return result;});

    std::cout<<std::endl;
    std::cout<<"last sqaure:"<<result<< " "<<std::endl;


    std::transform(numbers.begin(), numbers.end(), x.begin(), std::back_inserter(y), sum);

   for(int i:y)
   {
    std::cout<<i<<" ";
   }
   std::cout<<std::endl;
   std::transform(numbers.begin(), numbers.end(), x.begin(), x.begin(), [](int x, int y){std::cout<< x+y<<std::endl; return x+y;});


    return 0;
}
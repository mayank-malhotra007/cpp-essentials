
// the capture list [] stays empty for a stateless lambda

#include <iostream>

 std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec)
    {
        for(auto& val:vec)
        {
            os << val << " ";
        }

        return os;
    }


int main() {

   

    int x = 10;
    [](int x){std::cout << x << std::endl;}(100);

    int y = 200;
    int* p;
    p = &y;

    // passing a pointer to a lambda
    auto result = [](int* ptr){std::cout << *ptr << std::endl; };
    result(p);

    std::vector<int> test_scores1 = {100,200,300,400,500};
    std::vector<float> test_scores2 = {10.5, 21.3, 3.14};

    auto bonus = [](std::vector<int>& scores, int bonus_points){  
        for (auto &x: scores)
            x = x + bonus_points;
        };

    bonus(test_scores1, 5);

    std::cout << "printing test scores with bonus points" << std::endl;

    std::cout << test_scores1[0] << std::endl;
    std::cout << test_scores1[1] << std::endl;
    std::cout << test_scores1[2] << std::endl;
    std::cout << test_scores1[3] << std::endl;
    std::cout << test_scores1[4] << std::endl;


    std::cout << test_scores1; // overload << 

    // auto 
    
    auto final_value = [](auto& scores, int bonus_points){  
        for (auto &x: scores)
            x = x + bonus_points;
        };

    // we are able to pass both int and float to the same lamba expression
    final_value(test_scores1, 5);
    final_value(test_scores2, 3);

    // return a lambda from a function

    


    return 0;
}
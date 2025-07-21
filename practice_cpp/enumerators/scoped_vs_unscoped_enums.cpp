
#include <iostream>

enum Grocery_Item {Milk=100, Bread = 200, Butter=300};
enum class Employee {personA = 1, personB=2, personC=3};

int main()
{
    std::cout << Milk + Bread + Butter << std::endl;
    
    std::cout << int(Employee::personA) + static_cast<int>(Employee::personB) + 
    static_cast<std::underlying_type_t<Employee>>(Employee::personC) << std::endl;


    return 0;
}
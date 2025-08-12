
/*
CLASS TEMPLATES and generic programming
*/


#include<iostream>
#include<vector>
#include<utility>

class Employee{

    std::string name;
    double salary;

    public:
        Employee(){std::cout<<"default"<<std::endl;};
        Employee(std::string x, double y): name{x}, salary(y) {};

        std::string get_Name()
        {
            return name;
        }

        double get_Salary()
        {
            return salary;
        }

        ~Employee(){std::cout<<"destructor called for Employee"<<std::endl; };


};



// class Template
template <typename T1, typename T2, typename T3=std::nullptr_t>
class Employee2
{
    T1 name;
    T2 salary;
    T3 rank;

    public:
        Employee2(){std::cout<<"default"<<std::endl;};
        Employee2(T1 x, T2 y): name{x}, salary{y}, rank{0} {};
        Employee2(T1 x, T2 y, T3 r): name{x}, salary{y}, rank{r} {};

        T1 get_Name() 
        {
            return name;
        }

        T2 get_Salary() 
        {
            return salary;
        }

        T3 get_Rank()
        {
            return rank;
        }

        ~Employee2(){std::cout<<"destructor called for Employee2"<<std::endl; };

};


template <typename T1, typename T2, typename T3>
std::ostream& operator<<(std::ostream& os,  Employee2<T1,T2,T3>& rhs)
{
    // check if vector is available
    if constexpr(requires{rhs.get_Salary().begin();})
    {
        for(auto i:rhs.get_Salary())
        {
            os << i << " ";
        }
    }
    
    // check if pair is available
    if constexpr(requires {rhs.get_Rank().first; rhs.get_Rank().second;} )
    {

        auto p1 = rhs.get_Rank();
        os<<p1.first<<" "<<p1.second<<std::endl;
       
    }
     return os;
}




int main()
{
    Employee e1("david", 1000);
    std::cout <<e1.get_Name() << std::endl;
    std::cout <<e1.get_Salary() << std::endl;

    Employee2 e2("max", 123.45);
    std::cout <<e2.get_Name() << std::endl;
    std::cout <<e2.get_Salary() << std::endl;

    std::vector<int> s {1,2,3,4,5};
    std::pair<std::string, int>p {"colonel",100};        

    Employee2 e3("lucy", s);
    std::cout <<e3.get_Name() << std::endl;;
    std::cout << e3 << std::endl;
   
    Employee2 e4("lolu", s, p);
    std::cout << e4.get_Name() << std::endl;
    std::cout << e4 << std::endl;


    return 0;
}
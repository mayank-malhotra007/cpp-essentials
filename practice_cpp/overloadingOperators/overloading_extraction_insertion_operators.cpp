

// Overloading  << and  >> operators //


#include <iostream>



class Employee{

    std::string name;
    int age;
    float salary;

    public:

    Employee(){name="none"; age=0; salary=0.0;};

    Employee(std::string name, int age, float salary):name{name},age{age},salary{salary} {}

    //setters

    void set_name(std::string n){
        name = n;
    }

    void set_age(int a)
    {
        age = a;
    }

    void set_salary(float s)
    {
        salary = s;
    }

    void display()
    {
        std::cout << "[" << name << ":" << age << ":" << salary << "]" << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, Employee& rhs);
    friend std::istream& operator>>(std::istream& is, Employee& rhs);
};



// overload the "<<" operator
std::ostream& operator<<(std::ostream& os, Employee& rhs)
{
    os << rhs.name << ":" << rhs.age << ":" << rhs.salary << std::endl;


    return os;
}



// overload the ">>"  operator
std::istream& operator>>(std::istream& is, Employee& e)
{
    std::cout << "enter name: ";
    is >> e.name;

    std::cout << "enter age: ";
    is >> e.age;

    std::cout << "enter salary: ";
    is >> e.salary;

    return is;
}





int main(){

    Employee e1;
    e1.set_name("David");
    e1.set_age(10);
    e1.set_salary(4000.01);

    std::cout << e1 << std::endl; // << gets overloaded

    Employee e2;
    std::cin>>e2;
    std::cout << e2 << std::endl;

    return 0;
}
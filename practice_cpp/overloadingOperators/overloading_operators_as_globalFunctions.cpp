
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

    friend std::unique_ptr<Employee> operator+(Employee& lhs, Employee& rhs);

};




std::unique_ptr<Employee> operator+(Employee& lhs, Employee& rhs)
{
    //Employee result;

    auto p= std::make_unique<Employee> ();
    

    p->name = lhs.name + " " + rhs.name; // we can concatenate std::string C++ string
    p->age = lhs.age + rhs.age;
    p->salary = lhs.salary + rhs.salary;

    return p; // returns a pointer, focus on the return type
}



int main() {


    Employee e1; // invokes default const

    e1.set_name("Bob");
    e1.set_age(50);
    e1.set_salary(20000);
    e1.display();

    Employee e2("David", 43, 10000); // invokes 3args constructor
    e2.display();

    
    
    auto e3 = e1 + e2;
    e3->display();

    
    return 0;

}
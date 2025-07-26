
// in this example we overload a constructor of class MyString

#include <iostream>
#include <cstring> // for strcpy

class MyString {

    int age = 0;
    char name[20]; // c style string

    public:
        // default const
        MyString(){std::cout << "default" << std::endl;}; 
        
        // Overloaded constructor
        MyString(const MyString* s){
         age = s->age;
         std::strcpy(name, s->name);

        };                    

        // Copy constuctor
        MyString(const MyString& cp){
           age = cp.age;
           std::strcpy(name, cp.name);
        };                 // copy const

        void set_name();
        void set_age();
        void display();



        ~MyString(){std::cout << "destructor called" << std::endl;};

};


void MyString :: set_name()
{
    std::cout << "enter name: ";
    std::cin >> name;
}

void MyString :: set_age()
{
    std::cout << "enter age: ";
    std::cin >> age;
}

void MyString :: display()
{
    std::cout << name << ":" << age << std::endl;
}






int main() {

    
    MyString obj1;
    obj1.set_name();
    obj1.set_age();
    obj1.display();

    MyString* p; // pointer to a class 
    p = &obj1;


    MyString obj2(p); // overloaded const is called
    
    MyString obj3(obj1);  // copy const is called

    obj2.display();
    obj3.display();

    return 0;
}


// overloading member methods 
#include <iostream>
#include <cstring>


class Person{

    char name[20];
    int age = 0;

    public:
    Person(){}

    Person(const char* str): age(0)
    {
        std::strcpy(name, str);
    }

    // collects trhe object by reference
     Person operator-(Person& rhs){
        Person result;

        std::cout << rhs.name << std::endl;

        for(int i=0 ; i < sizeof(rhs.name); i++)
        {
           
            result.name[i] = std::tolower(rhs.name[i]);
        }

        return result;
    }

    /*
   // p1 is already passed in, p2 is in the rhs
    Person operator+(Person& rhs){

        Person result;
        strcpy(result.name,name);
        strcat(result.name," ");
        strcat(result.name, rhs.name);

        return result; // p3 gets this

    }
    */

    void display()
    {
        std::cout << name  << std::endl;
    }

    // overloading as a friend function
    friend Person operator+(Person& lhs, Person& rhs)
    {
        Person result;
        strcpy(result.name,lhs.name);
        strcat(result.name," ");
        strcat(result.name, rhs.name);

        return result; // p3 gets this
    }

};



int main() {

    Person p1 {"DAVID"};
    p1.display();

    Person p2 = p1-p1; // operator- is invoked
    p2.display();


    Person p3;
    p3 = p1 + p2;   // operator+ is invoked, p1 calls the + operator and p2 is passed as an object
    p3.display();


    


    return 0;
}
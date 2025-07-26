
#include <iostream>

class MyString {
    int age = 0;
    std::unique_ptr<char[]> name;

    

public:
    // Default constructor
    MyString() {
        std::cout << "default constructor" << std::endl;
    }

    MyString(const char* str, int a=0):age(a)
    {
        set_name(str);
    }


    // Overloaded constructor from pointer (not common practice)
    MyString(const MyString* s) {
        std::cout << "overloaded constructor from pointer" << std::endl;
        if (s) {
            age = s->age;
            if (s->name) {
                size_t len = std::strlen(s->name.get()) + 1;
                name = std::make_unique<char[]>(len);
                std::strcpy(name.get(), s->name.get());
            }
        }
    }

    // Copy constructor (deep copy)
    MyString(const MyString& cp) {
        std::cout << "copy constructor called" << std::endl;
        age = cp.age;
        if (cp.name) {
            size_t len = std::strlen(cp.name.get()) + 1;
            name = std::make_unique<char[]>(len);
            std::strcpy(name.get(), cp.name.get());
        }
    }

    // Assignment operator (deep copy)
    MyString& operator=(const MyString& rhs) {
        std::cout << "assignment operator..." << std::endl;
        if (this == &rhs)
            return *this;

        age = rhs.age;
        if (rhs.name) {
            size_t len = std::strlen(rhs.name.get()) + 1;
            name = std::make_unique<char[]>(len);   // smart pointer to the array of characters 
            std::strcpy(name.get(), rhs.name.get());
        } else {
            name.reset();
        }

        return *this;
    }

    void set_name(const char* str) {
        if (str) {
            size_t len = std::strlen(str) + 1;
            name = std::make_unique<char[]>(len);
            std::strcpy(name.get(), str);
        }
    }

    void set_age(int a) {
        age = a;
    }

    void display() const {
        std::cout << "Name: " << (name ? name.get() : "null") << ", Age: " << age << std::endl;
    }

    // move assignment 
    MyString& operator=(MyString&& rhs)
    {
          std::cout << "Move assignment called" << std::endl;

        if(this == &rhs)
            return *this;
        
        std::cout << rhs.name << ":" << rhs.age << std::endl;

        age=rhs.age;
        name = std::move(rhs.name); // sets rhs.name to null after this 
        rhs.age=0;

        // manual
        /*
            delete[] name;
            name = rhs.name;
            rhs.name = nullptr;
        */

        return *this;
    }


    ~MyString() {
        std::cout << "destructor called" << std::endl;
    }
};




int main() {

    MyString s1 {"Hello"};
    s1 = "Frank"; //move assignment, here it does not call the copy const because rvalue is not an object its a temp

    MyString s2;
    s2.set_name("David");
    s2.set_age(10);
    s2.display();

    MyString s3 = s2; // copy constructor called

    MyString s4;
    s2 = s4; // assignment operator=(const MyString& rhs) invoked
    
    
    return 0;
}
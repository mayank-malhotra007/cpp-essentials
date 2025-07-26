#include <iostream>
#include <cstring>
#include <memory>

class MyString {
    int age = 0;
    std::unique_ptr<char[]> name;

    

public:
    // Default constructor
    MyString() {
        std::cout << "default constructor" << std::endl;
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
            name = std::make_unique<char[]>(len);
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

    ~MyString() {
        std::cout << "destructor called" << std::endl;
    }
};

int main() {
    MyString obj1;
    obj1.set_name("Alice");
    obj1.set_age(25);
    obj1.display();

    MyString obj3;
    obj3.set_name("Bob");
    obj3.set_age(30);
    obj3.display();

    MyString obj2 = obj3; // copy constructor
    obj2.display();

    obj2 = obj1; // assignment operator
    obj2.display();

    MyString obj4(&obj1); // overloaded constructor
    obj4.display();

    return 0;
}

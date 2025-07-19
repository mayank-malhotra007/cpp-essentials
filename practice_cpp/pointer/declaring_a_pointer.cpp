#include <iostream>


int main() {
   
    int *p1 {nullptr};
    char *p2 {nullptr};
    double *p3 {nullptr};
    std::vector<std::string> *p4 {nullptr};

    int x = 10;
    char c = 'a';
    double num = 100.05;
    std::vector<std::string> name = {"mayank"};
    
    p1 = &x;
    p2 = &c;
    p3 = &num;
    p4 = &name;

    std::cout << "printing addresses:" << std::endl;
    std::cout << p1 << std::endl << static_cast<void*>(p2) << std::endl << p3 << std::endl << p4 << std::endl;

    std::cout << "printing values:" << std::endl;
    std::cout << *p1 << std::endl << *p2 << std::endl << *p3 << std::endl << (*p4)[0] << std::endl;

    return 0;
}

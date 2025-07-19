
#include <iostream>

int main () {
    
    // integer variable
    int *int_ptr {nullptr};
   
    int_ptr = new int;  // dynamic memory allocation

    *int_ptr = 100;

    std::cout << "address:" << int_ptr << std::endl;
    std::cout << "value:"  << *int_ptr << std::endl;

    delete int_ptr;

    // array
    int *array_ptr {nullptr};

    array_ptr = new int[10];  // dynamically created an array of 10 inetgers
    array_ptr[0] = 1000;     // init the first integer in array

    std::cout << "address:" << array_ptr << std::endl;
    std::cout << "value:" << *array_ptr << std::endl;
    
    delete [] array_ptr;

   
    // vector of 10 integer elements
    std::vector<int> *vector_ptr {nullptr};
    
    vector_ptr = new std::vector<int>(10); // one vector having 10 elements
    (*vector_ptr)[0] = 2000;

    std::cout << vector_ptr << std::endl;
    std::cout << (*vector_ptr)[0] << std::endl;
    delete vector_ptr;


   // vector of 10 vector objects

   vector_ptr = new std::vector<int>[10]; // a vector of 10 vector objects
   vector_ptr[0].push_back(3000);
   
   std::cout << vector_ptr[0][0] << std::endl;

   delete [] vector_ptr; 

    return 0;
}

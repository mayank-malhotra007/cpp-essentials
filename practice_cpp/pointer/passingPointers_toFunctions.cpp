
#include <iostream>
void add(int*, int*);         // collect in a pointer
int* multiply(int* , int*);   // returns a pointer

int main() {

    int a = 10;
    int b = 5;

    add(&a,&b); // pass by reference
    int* result = multiply(&a,&b);
    std::cout << *result << std::endl;

    return 0;
}

void add(int* x, int* y)
{
    std::cout << (*x) + (*y) << std::endl;
}


// returns a pointer
int* multiply(int* x, int* y)
{
    int temp = (*x) * (*y);
    int *result;
    result = &temp;
    return result;
}


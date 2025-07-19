
#include <iostream>

int main() {

   int numbers[] = {1,2,3,4,5};
   int *array_ptr {nullptr};

   array_ptr = numbers;
   // or
   // array_ptr = &numbers[0];

   std::cout << array_ptr << std:: endl << array_ptr+1 << std::endl << array_ptr+2 << std::endl;
   std::cout << array_ptr[0] << std::endl << *(array_ptr+1) << std::endl;

   // loop in array
   for (int i=0; i<5; i++)
   {
    std::cout << numbers[i];
   }

   std::cout << std::endl;

   // loop using pointers
   for(int j=0; j<5; j++)
   {
    std::cout << array_ptr[j];
   }

   std::cout << std::endl;
   // loop using pointer dereference

   for(int k=0; k<5; k++)
   {
    std::cout << *(array_ptr+k);
   }


    return 0;
}
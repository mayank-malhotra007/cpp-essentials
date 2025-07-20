
#include <iostream>

void displayMax(int*);
int* findMax(int*, int);


int main() {

    int numbers[] = {10,1,300,4,5};
    int size = 5;
    int* result;
    result = findMax(numbers, size);
    
    displayMax(result);
    
    return 0;
}


int* findMax(int* ptr_num, int size)
{
   if(size==0) return nullptr;

   int* maxPtr = ptr_num;

   for(int i=1; i<size; i++)
   {
    if(ptr_num[i] > *maxPtr)
    {
        maxPtr = &ptr_num[i];
    }
   }

    return maxPtr;

}

void displayMax(int* x)
{
    std::cout << "Max value is: " << *x << std::endl;
}
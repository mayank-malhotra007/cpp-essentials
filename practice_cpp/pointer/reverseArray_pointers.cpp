
#include <iostream>


void reverse_num(int*, int);
void reverse_string(char*, int);


int main() {
  
    int size = 5;
    int numbers[] = {1,2,3,4,5};

    char name [] = "Mayank Malhotra"; // C string
    int length = sizeof(name);

    reverse_num(numbers,size);

    for(int i=0; i<size; i++)
    {
        std::cout << numbers[i] << " " << std::endl;
    }

    std::cout << "string: " << name << std::endl;
    reverse_string(name,length);
    std::cout << "Reversed string: " << name << std::endl;


    return 0;
}



void reverse_num(int* ptr, int size)
{
    int temp;
    int* start = ptr;
    int* end = ptr+size-1;

    while(start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;

    }

}



void reverse_string(char* x, int length)
{
    char temp;
    char* start = x;
    char*end = x+length-2; // -2 because sizeof() includes null character!

    while(start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;

    }

}
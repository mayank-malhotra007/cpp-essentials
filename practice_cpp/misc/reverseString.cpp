
#include<iostream>


int main()
{

 // C-style string
 char name[] {"David"};

 int len_str = sizeof(name)-1; // includes the null char at end
 std::cout << len_str<<std::endl;

 //print
 for(int i=0; i<len_str;i++)
 {
    std::cout<<name[i];
 }
 
 std::cout<<std::endl;

 //reverse the string
 char* start=&name[0];
 char* end=&name[len_str-1]; //index=4
 char temp;

 while(start<end)
 {
    temp=*start;
    *start=*end;
    *end=temp;

    start++;
    end--;
 }


//print
 for(int i=0; i<len_str;i++)
 {
    std::cout<<name[i];
 }
 



 std::cout<<std::endl;

 return 0;



}

/*
  ITERATORS are pointers!
  
*/



#include<iostream>
#include<vector>


int main()
{
    std::vector<int> v{1,2,3};

    for(int i:v)
    {
        std::cout<<i<<" ";
    }

 //1st method
   auto begin=v.begin();
   auto end=v.end();

  std::cout<<std::endl;
  std::cout<<*begin<<std::endl;
  std::cout<<*(end-1)<<std::endl;

  while(begin<=end-1)
  {
    std::cout<<*begin<<" ";
    begin++;
  }

  std::cout<<std::endl;
  // 2nd method
  std::vector<int>::iterator it = v.begin();
  while(it!=v.end())
  {
    std::cout<<*it<<" ";
    it++;
  }

  std::cout<<std::endl;
  // vectors allow random access just like an array, but vectors are dynamic in size, user does not know the size initially.
  std::cout<<v[0];
  return 0;


}//end
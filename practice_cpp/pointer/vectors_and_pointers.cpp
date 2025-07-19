
#include <iostream>

int main() {
 
  // vector of ints  
  std::vector<int> numbers = {1,2,3,4,5};
  
  std::vector<int>* vec_ptr;
  vec_ptr = &numbers;   // we use the '&' for vectors , not used in arrays

  // simply loop in the vector
  for(int i: numbers)
  {
    std::cout << i << " ";
  }

  std::cout << std::endl;

  // loop using the pointer
  for(int j=0; j<vec_ptr->size(); j++)
  {
    std::cout << (*vec_ptr)[j] << " ";
  }

  std::cout << std:: endl;

  // using the vec_ptr
  for(int k: *vec_ptr)
  {
    std::cout << k << " ";
  }

  // for a vector string
  std::vector<std::string> name = {"Malhotra", "Mayank"};

  std::cout << std::endl;

  for(auto i: name)
  {
    std::cout << i << " ";
  }

  // pointer to a vector string
  std::vector<std::string>* ptr;
  ptr = & name;

  std::cout << std::endl;

  for(auto c: *ptr)
  {
    std::cout << c << " ";
  }

  
    return 0;
}

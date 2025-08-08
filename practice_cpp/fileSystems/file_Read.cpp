
#include <iostream>
#include <fstream>



int main() {
    std::ifstream in_file("/Users/optimus/Desktop/example.txt", std::ios::in);

    std::string line;


    if(in_file)
    {
        std::cout << "file opened" << std::endl;
        while(std::getline(in_file, line))
        {
            
            std::cout << line << std::endl;
        }
    }

    in_file.close();
    std::cout << "file closed" << std::endl;
    return 0;
}



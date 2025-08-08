
#include <iostream>
#include <fstream>

int main()
{
    std::string path;
    
    std::fstream in_file;
    std::string line;

    std::cout << "enter file path: ";
    std::cin >> path;

    in_file.open(path, std::ios::in); 

    if(in_file)
    {
        while(std::getline(in_file, line))
        {
            std::cout << line ;
        }
    }

    in_file.close();
    return 0;
}

#include<iostream>
#include<fstream>

int main()
{
    std::string phrase {"Strength lies in calmness"};

    std::ofstream out_file("/Users/optimus/Desktop/exampleWrite.txt", std::ios::out);
    
    if(out_file)
    {
        std::cout << "file opened" << std::endl;
        out_file << phrase;
    }else
    {
        std::cerr << "file open failed!" << std::endl;
    }

    out_file.close();
    std::cout << "file closed" << std::endl;
    return 0;
}
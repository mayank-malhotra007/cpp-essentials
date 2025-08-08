
#include <iostream>
#include <fstream>

int main(){

    std::ofstream out_file("/Users/optimus/Desktop/test.txt", std::ios::app);
    std::ifstream in_file("/Users/optimus/Desktop/example.txt", std::ios::in);

    char c;

    if(in_file && out_file)
    {
        std::cout << "files opened" << std::endl;
        while(in_file.get(c))
        {
            out_file.put(c);
        }

    }else
    {
        std::cerr << "file open failed" << std::endl;
    }

    std::cout << "file copied" << std::endl;
    in_file.close();
    out_file.close();
    std::cout << "files closed" << std::endl;

    return 0;
}
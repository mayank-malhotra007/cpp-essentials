
#include<iostream>
#include<fstream>


int main()
{
    std::ifstream in_file("/Users/optimus/Desktop/example.txt", std::ios::in);
    std::ofstream out_file("/Users/optimus/Desktop/exampleWrite.txt", std::ios::app);

    std::string line;
    
    int count =0;
    if(in_file && out_file)
    {
        std::cout << "files opened" << std::endl;

        while(std::getline(in_file, line))
        {
            out_file<<line<<'\n';
            count++;
        }

    }else{
        std::cerr << "file open failed" << std::endl;
    }

    std::cout <<"lines copied: " << count << std::endl;
    
    in_file.close();
    out_file.close();
    std::cout << "files closed" << std::endl;


    return 0;
}

#include <iostream>


int divide2numbers(int& a, int& b)
{
    if(b==0)
    {
        throw 0;
    }
    else if(a<0 && b<0)
    {
        throw std::string("error");
    }
    else
    {
     return a/b;
    }
    
}


int main() {

    int x = -200;
    int y = -20;

    // functions that could give unexpected results, put them in the try block

    try{


        int result = divide2numbers(x,y);
        std::cout << result << std::endl;
    }

    catch(int& ex)
    {
        std::cerr << "cant divide by 0" << std::endl;
    }

    catch(std::string& s)
    {
        std::cout << s << std::endl;
    }

    catch(...)
    {
        std::cout << "all exceptions caught here" << std::endl;
    }


    return 0;
}
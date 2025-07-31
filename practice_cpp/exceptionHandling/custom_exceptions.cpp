
#include <iostream>


class TemperatureException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "temp too hot!";
    }
};


class Heater{

    public:

        void setTemp(int temp)
        {
            if(temp>100)
            {
                throw TemperatureException(); // return an object of this class
            }
            else
            {
                std::cout <<temp << std::endl;
            }
        }
};


int main(){

    int temp = 101;
    Heater h;
    
    try
    {
        h.setTemp(temp);
    } catch(TemperatureException& e)
    {
        std::cout << e.what();
    }


    return 0;
}


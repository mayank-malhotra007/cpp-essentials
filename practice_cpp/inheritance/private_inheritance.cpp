
#include <iostream>

class Engine {


    private:

        //double bhp;
        //#int cc;

    public:

        void start()
        {
            std::cout << "engine started" << std::endl;
        }

        void stop() 
        {
            std::cout << "engine stopped" << std::endl;
        }


};



class Car : private Engine {

    public:
        void drive() {
            start();
            std::cout << "car is driving" << std::endl;
        }

        void park()
        {
            stop();
            std::cout << "car parked" << std::endl;
        }


};


int main()
{
    Car car;
    car.drive();
    car.park();
    //car.start();
    //car.stop();

    return 0;
}
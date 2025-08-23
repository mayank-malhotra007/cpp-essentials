
/*
    Timer HH:MM:SS

    HH 0 to 24
    MM 0 to 60
    SS 0 to 60

*/



#include<iostream>
#include<iomanip>
#include<thread>
#include<chrono>



int main(){

    int hours=0, minutes=0, seconds=0;

    while(1)
    {
        seconds+=1;
    
        if(seconds>=60)
        {
            minutes++;
            seconds=0;
        }
        if(minutes>=60)
        {
            hours++;
            minutes=0;
        }
        if(hours>24)
        {
            hours=0;
        }

        // Print with zero padding (HH:MM:SS)
        std::cout << "\r"
                  << std::setw(2) << std::setfill('0') << hours << ":"
                  << std::setw(2) << std::setfill('0') << minutes << ":"
                  << std::setw(2) << std::setfill('0') << seconds
                  << std::flush;

    
    }

    // wait for 1sec
    std::this_thread::sleep_for(std::chrono::seconds(1));


    


    return 0;
}
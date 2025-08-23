#include <iostream>
#include <iomanip>   // std::setw, std::setfill, std::put_time
#include <thread>    // std::this_thread::sleep_for
#include <chrono>    // std::chrono::seconds
#include <ctime>     // std::tm

int main() {
    int hours = 0, minutes = 0, seconds = 0;

    while (true) {
        // increment and roll over
        seconds++;
        if (seconds >= 60) { seconds = 0; minutes++; }
        if (minutes >= 60) { minutes = 0; hours++; }
        if (hours > 24)    { hours = 0; }

        // Put into a tm struct for nice formatting
        std::tm t{};
        t.tm_hour = hours;
        t.tm_min = minutes;
        t.tm_sec = seconds;

        // Carriage return to overwrite previous output
        std::cout << "\r" 
                  << std::put_time(&t, "%H:%M:%S")
                  << std::flush;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

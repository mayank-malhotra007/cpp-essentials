
// need of scope resolution operator; safer to use, avoid name clashes as well.

#include <iostream>

enum class Whale {Blue, Beluga, Gray};
enum class Shark {Greatwhite, Hammerhead, Blue};


int main()
{

    Whale whale;
    Shark shark;

    std::cout << "enter type of whale: ";
    std::underlying_type_t<Whale> input;
    std::cin >> input;

    if(input>=0 && input<=2)
    {
        whale = static_cast<Whale>(input);
    }

    switch(whale)
    {
        case Whale::Blue   :std::cout << "whale" << std::endl; break;
        case Whale::Beluga : std::cout << "beluga" << std::endl; break;
        case Whale::Gray   : std:: cout << "gray" << std::endl; break;
        default            : std::cout << "Invalid Choice" << std::endl;
    }
    


    return 0;
}
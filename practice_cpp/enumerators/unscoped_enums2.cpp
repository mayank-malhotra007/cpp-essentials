#include <iostream>

enum State {Off, On, Hot, Cold};


int main()
{

    State state_enum;
    std::cout << "Enter state: ";

    std::underlying_type_t<State> input; // as std::in cant overload enum object // not a type cast but a type alias.
    std::cin >> input;

    if(input >=0 && input<=3)
    {
        state_enum = static_cast<State>(input); // converts the int back into State Enum
    }

    switch(state_enum)
    {
        case Off: std::cout << "Off" << std::endl; break;
        case On:  std::cout << "On" << std::endl; break;
        case Hot: std::cout << "Hot" << std::endl; break;
        case Cold:std::cout << "Cold" << std::endl; break;
        default: std::cout << "Invalid" << std::endl; break;
    }

    return 0;

}
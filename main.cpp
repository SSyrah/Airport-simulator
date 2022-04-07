#include "Header.h"
#include "option.h"

int main()
{
    int option{};

    std::cout << "Choose Airport version 1-5:  ";
    std::cin >> option;

    switch (option)
    {
    case 1:
        main_1();
        break;
    case 2:
        main_2();
        break;
    case 3:
        main_3();
        break;
    case 4:
        main_4();
        break;
    case 5:
        main_5();
        break;
    default:
        std::cout << "Wrong option, try again.\n";
        break;
    }
}
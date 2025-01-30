#include "Complex.h"
#include <iostream>

int main(void) {
    Complex c1;
    Complex c2;

    std::cout << "Enter a complex number: ";
    if (std::cin >> c1) {
        std::cout << "You entered: " << c1 << std::endl;
    } else {
        std::cerr << "Invalid input format!!!!" << std::endl;
    }

    std::cout << "Enter another complex number: ";
    std::cin.clear(); /* Clear the error state */

    if (std::cin >> c2) {
        std::cout << "You entered: " << c2 << std::endl;
    } else {
        std::cerr << "Invalid input format." << std::endl;
    }

    return 0;
}
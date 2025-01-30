#include "Point.h"
#include <iostream>

int main(void) {
    Point p1;
    Point p2;

    std::cout << "Enter a point (format: (x, y)): ";
    if (std::cin >> p1) {
        std::cout << "You entered: " << p1 << std::endl;
    } else {
        std::cerr << "Invalid input format." << std::endl;
        std::cin.clear(); /* Clear the error state */
    }

    std::cout << "Enter another point (format: (x, y)): ";
    if (std::cin >> p2) {
        std::cout << "You entered: " << p2 << std::endl;
    } else {
        std::cerr << "Invalid input format." << std::endl;
        std::cin.clear(); /* Clear the error state */
    }

    return 0;
}
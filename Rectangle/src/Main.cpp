#include "Rectangle.h"
#include <iostream>

int main(void) {
    Rectangle r(3.0, 5.0);
    std::cout<<"Permeter: "<<r.Perimeter()<<std::endl;
    std::cout<<"Area: "<<r.Area()<<std::endl;
}
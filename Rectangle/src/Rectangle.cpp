#include "Rectangle.h"

Rectangle::Rectangle()
{
    this->length = 1.0;
    this->width = 1.0;
}

Rectangle::Rectangle(double len, double wdt)
{
    setLength(len);
    setWidth(wdt);
}

double Rectangle::Perimeter()
{
    return 2.0*(this->getLength() + this->getWidth());
}

double Rectangle::Area()
{
    return getLength() * getWidth();
}

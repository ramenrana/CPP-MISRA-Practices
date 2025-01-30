/*
Create a class Rectangle with attributes
length and width , each of which defaults to 1. Provide member
functions that calculate the perimeter and the area of the
rectangle. Also, provide set and get functions for the length
and width attributes. The set functions should verify that length
and width are each floating-point numbers larger than 0.0 and
less than 20.0.
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rectangle
{
private:
    double length;
    double width;
public:
    Rectangle(/* args */);
    Rectangle(double, double);
    ~Rectangle() = default;
    double Perimeter();
    double Area();

    double getLength() const { return length; }
    void setLength(double length_) {
        if (length_ > 0.0 && length_ <= 20.0) 
            length = length_; 
        else 
            std::cerr<<"Please enter the length between 0 - 20";
    }

    double getWidth() const { return width; }
    void setWidth(double width_) { 
        if (width_ > 0.0 && width_ <= 20.0) 
            width = width_;
        else 
            std::cerr<<"Please enter the width between 0 - 20";
        width = width_; 
    }
};


#endif // RECTANGLE_H

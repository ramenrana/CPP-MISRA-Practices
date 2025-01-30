#include "Point.h"

/**
 * @brief Construct a new Point:: Point object
 * 
 * @param xCoordinate x coordinate of the point
 * @param yCoordinate y coordinate of the point
 */
Point::Point(int xCoordinate, int yCoordinate)
{
    this->xCoordinate = xCoordinate;
    this->yCoordinate = yCoordinate;
}

/**
 * @brief Stream insertion operator for Point object
 * 
 * @param os Output stream
 * @param rhs Point object
 * @return std::ostream& Output stream for cascading calls
 */
std::ostream &operator<<(std::ostream &os, const Point &rhs) {
    os << "xCoordinate: " << rhs.xCoordinate
       << " yCoordinate: " << rhs.yCoordinate;
    return os;
}

/**
 * @brief Stream extraction operator for Point object
 * 
 * @param in Input stream
 * @param rhs Point object
 * @return std::istream& Input stream for cascading calls
 */
std::istream &operator>>(std::istream &in, Point &rhs)
{
    char ch1, ch2, ch3;
    int x, y;
    in >> ch1 >> x >> ch2 >> y >> ch3;

    if (in.fail() || ch1 != '(' || ch2 != ',' || ch3 != ')') {
        in.setstate(std::ios::failbit);
    } else {
        rhs.xCoordinate = x;
        rhs.yCoordinate = y;
    }

    return in;
}


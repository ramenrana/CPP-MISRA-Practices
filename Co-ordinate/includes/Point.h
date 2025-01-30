#ifndef POINT_H
#define POINT_H
#include <sstream>

class Point
{
private:
    int xCoordinate;
    int yCoordinate;
public:
    /**
     * @brief Construct a new Point object
     * @param xCoordinate for xcoordinate of the point
     * @param yCoordinate for ycoordinate of the point
    */
    Point(int xCoordinate = 0, int yCoordinate = 0);

    /**
     * @brief Destructure set to default for deleting the Point object 
    */
    ~Point() = default;

    /**
     * @brief Getter function for getting the XCoordinate
     * @return int
    */
    int getXCoordinate() const { return xCoordinate; }
    
    /**
     * @brief Setter function for setting the XCoordinate number
     * @param xCoordinate_
    */
    void setXCoordinate(int xCoordinate_) { xCoordinate = xCoordinate_; }

    /**
     * @brief Getter function for getting the XCoordinate number
     * @return int
    */
    int getYCoordinate() const { return yCoordinate; }

    /**
     * @brief Setter function for setting the yCoordinate number
     * @param yCoordinate_
    */
    void setYCoordinate(int yCoordinate_) { yCoordinate = yCoordinate_; }

    /* stream insertion and stream extraction operators */
    friend std::ostream &operator<<(std::ostream &os, const Point &rhs);
    friend std::istream &operator>>(std::istream &in, Point &rhs);
};



#endif // POINT_H

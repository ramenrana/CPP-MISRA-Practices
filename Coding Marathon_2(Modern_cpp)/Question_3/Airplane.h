#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <iostream>
#include "AirPlaneType.h"

class Airplane
{
private:
    /* data */
    std::string airPlaneManufacturer;
    AirPlaneType airPlaneType;
    int airPlaneSeatCount;

public:
    Airplane(/* args */) = delete;
    Airplane(const Airplane &obj) = delete;
    Airplane(Airplane &&obj) = delete;
    Airplane(std::string Manufacturer, AirPlaneType airPlaneType_, int seatCount);

    ~Airplane();

    std::string getAirPlaneManufacturer() const { return airPlaneManufacturer; }
    void setAirPlaneManufacturer(const std::string &airPlaneManufacturer_) { airPlaneManufacturer = airPlaneManufacturer_; }

    AirPlaneType getAirPlaneType() const { return airPlaneType; }
    void setAirPlaneType(const AirPlaneType &airPlaneType_) { airPlaneType = airPlaneType_; }

    int getAirPlaneSeatCount() const { return airPlaneSeatCount; }
    void setAirPlaneSeatCount(int airPlaneSeatCount_) { airPlaneSeatCount = airPlaneSeatCount_; }

    friend std::ostream &operator<<(std::ostream &os, const Airplane &rhs);
};

/*
    A FUNCTION TO DISPLAY AN AIRPLANE TYPE
*/

std::string DisplayAirPlaneType(AirPlaneType type);

#endif // AIRPLANE_H

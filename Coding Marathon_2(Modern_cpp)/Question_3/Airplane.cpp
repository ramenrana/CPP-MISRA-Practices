#include "Airplane.h"

/*
    Parametrized constructor for class Air Plane
*/
Airplane::Airplane(std::string Manufacturer, AirPlaneType airPlaneType_, int seatCount)
    : airPlaneManufacturer(Manufacturer), airPlaneType(airPlaneType_), airPlaneSeatCount(seatCount)
{
}

/*
    A destructor of class Airplane
*/
Airplane::~Airplane()
{
    std::cout << "AIRPLANE DESTROYED\n";
}

/*
    Overlaoded operator << to display all the details of the class Airplane
*/

std::ostream &operator<<(std::ostream &os, const Airplane &rhs)
{
    os << "airPlaneManufacturer: " << rhs.airPlaneManufacturer
       << " airPlaneType: " << DisplayAirPlaneType(rhs.airPlaneType)
       << " airPlaneSeatCount: " << rhs.airPlaneSeatCount;
    return os;
}

/*
    A function to display an airplane type
*/
std::string DisplayAirPlaneType(AirPlaneType type)
{
    if (type == AirPlaneType::CRUISELINEER)
    {
        return "CRUISELINEER";
    }
    else if (type == AirPlaneType::JUMBO)
    {
        return "JUMBO";
    }
    else
    {
        return "NEO";
    }
}

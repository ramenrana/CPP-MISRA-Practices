#include "Flight.h"

/*
    An overlaoded operator << to print all the details of the class flight
*/
std::ostream &operator<<(std::ostream &os, const Flight &rhs)
{
    os << "flightOperatorCompany: " << rhs.flightOperatorCompany
       << " flightOperatorType: " << DisplayOperatorType(rhs.flightOperatorType)
       << " flightAssociatedPlane: " << rhs.flightAssociatedPlane.get();
    return os;
}

/*
    A function to display type of an operator
*/

std::string DisplayOperatorType(FlightOperatorType type)
{
    if (type == FlightOperatorType::DOMESTIC)
    {
        return "DOMESTIC";
    }
    else
    {
        return "INTERNATIONAL";
    }
}

/*
    Parametrized cosntrutor of calss flight
*/

Flight::Flight(std::string company, FlightOperatorType operatorType, Reference associatedPlane)
    : flightOperatorCompany(company), flightOperatorType(operatorType), flightAssociatedPlane(associatedPlane)
{
}

/*
    Destructor of class flight
*/

Flight::~Flight()
{
    std::cout << "FLIGHT DESTROYED\n";
}

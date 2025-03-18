#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include "FlightOperatorType.h"
#include <memory>
#include "Airplane.h"

using Reference = std::reference_wrapper<std::shared_ptr<Airplane>>;

class Flight
{
private:
    std::string flightOperatorCompany;
    FlightOperatorType flightOperatorType;
    Reference flightAssociatedPlane;

public:
    //@Default Constructor is disabled
    Flight(/* args */) = delete;
    //@Copy Constructor is disabled/enabled
    Flight(const Flight &obj) = delete;
    //@Move Constructor is disabled/enabled
    Flight(Flight &&obj) = delete;
    //@Parameterized Constructor by passing  __  argument
    Flight(std::string company, FlightOperatorType operatorType, Reference associatedPlane);
    //@Destructor : for destroying the ___ object 
    ~Flight();
    
    
    //@Getter & Setter functions
    std::string getFlightOperatorCompany() const { return flightOperatorCompany; }
    void setFlightOperatorCompany(const std::string &flightOperatorCompany_) { flightOperatorCompany = flightOperatorCompany_; }

    FlightOperatorType getFlightOperatorType() const { return flightOperatorType; }
    void setFlightOperatorType(const FlightOperatorType &flightOperatorType_) { flightOperatorType = flightOperatorType_; }

    Reference getFlightAssociatedPlane() const { return flightAssociatedPlane; }
    void setFlightAssociatedPlane(const Reference &flightAssociatedPlane_) { flightAssociatedPlane = flightAssociatedPlane_; }

    //overload ostream << operator for displaying the data member of this class
    friend std::ostream &operator<<(std::ostream &os, const Flight &rhs);
};

/*
    A function to display oerator type of flight
*/
std::string DisplayOperatorType(FlightOperatorType type);

#endif // FLIGHT_H

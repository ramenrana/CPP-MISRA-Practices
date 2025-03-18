#include "Flight.h"
#include "FlightTicket.h"
#include "Airplane.h"
#include <iostream>
#include <list>
#include <memory>
#include <functional>

using Pointer = std::shared_ptr<FlightTicket>;

using Container = std::list<Pointer>;
using AirplaneContainer = std::list<std::reference_wrapper<std::shared_ptr<Airplane>>>;
using FlightContainer = std::list<std::reference_wrapper<std::shared_ptr<FlightTicket>>>;

/*
    A function to create objects of flightTicket
*/

extern std::function<void(Container &data)> CreateObjects;

/*
    A function to find and return all the airplane instances form a container
    of flightTicket instances for which flight operator type is domestic
*/

extern std::function<AirplaneContainer(Container &data)> AirplaneInstanceofTypeDomestic;

/*
    A function to find and retrun the airplane type for the flight ticket instance
    with the highest flight ticket price value
*/

extern std::function<AirPlaneType(Container &data)> AirPlaneTypeHighestTicketPrice;

/*
    A function to find and return all instances of airplane type of which
    flight ticket prices are above a threshold value passed as  an argument
*/

extern std::function<AirplaneContainer(Container &data, float threshold)> AirPlaneInstanceAboveThreshold;

/*
    A function to find and retrun the flight instances for the flightTIcket
    whose flightTicketNumber is provided as an argument to the function
*/

extern std::function<std::shared_ptr<Flight>(Container &data, std::string number)> FindByFlightTicketNumber;

/*
    A function to find an retrun the air plane type of the associated flight isntances
    airplane instance for which the flight ticket number is provided as an argument to the
    function
*/

extern std::function<AirPlaneType(Container &data, std::string number)> AirplaneTypeByTicketNumber;
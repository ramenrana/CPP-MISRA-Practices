#include "Flight.h"
#include "FlightTicket.h"
#include "Airplane.h"
#include <iostream>
#include <list>
#include <memory>
#include <functional>
#include "Functionalities.h"

/*
    OBJECTS OF CLASS AIRPLANE
*/
auto Air1 = std::make_shared<Airplane>("A", AirPlaneType::NEO, 200);
auto Air2 = std::make_shared<Airplane>("B", AirPlaneType::CRUISELINEER, 300);
auto Air3 = std::make_shared<Airplane>("C", AirPlaneType::JUMBO, 400);
auto Air4 = std::make_shared<Airplane>("D", AirPlaneType::NEO, 500);

/*
    OBJECT OF CLASS FLIGHT
*/
auto Fl1 = std::make_shared<Flight>("FL1", FlightOperatorType::DOMESTIC, std::ref(Air1));
auto Fl2 = std::make_shared<Flight>("FL2", FlightOperatorType::INTERNATIONAL, std::ref(Air2));
auto Fl3 = std::make_shared<Flight>("FL3", FlightOperatorType::DOMESTIC, std::ref(Air3));
auto Fl4 = std::make_shared<Flight>("FL4", FlightOperatorType::INTERNATIONAL, std::ref(Air4));

/*
    A function to create objects of flightTicket
*/
std::function<void(Container &data)> CreateObjects = [](Container &data)
{
    // Create flight tickets and add them to the container
    data.emplace_back(
        std::make_shared<FlightTicket>(
            "1",
            FlightTicketCategory::BUSINESS,
            std::ref(Fl1),
            100101.0f));
    data.emplace_back(
        std::make_shared<FlightTicket>(
            "2",
            FlightTicketCategory::ECONOMY,
            std::ref(Fl2),
            12142.0f));
    data.emplace_back(
        std::make_shared<FlightTicket>(
            "3",
            FlightTicketCategory::PREMIUM,
            std::ref(Fl3),
            29839.0f));
    data.emplace_back(
        std::make_shared<FlightTicket>(
            "4",
            FlightTicketCategory::ECONOMY,
            std::ref(Fl4),
            23232.0f));
};

/*
    A function to find and return all airplane instances whose flight operator type is domestic.
*/
std::function<AirplaneContainer(Container &data)> AirplaneInstanceofTypeDomestic = [](Container &data)
{
    if (data.empty())
    {
        throw std::runtime_error("list is empty!!");
    }
    AirplaneContainer result;
    for (auto &a : data)
    {
        if (a->getFlightTicketAssociatedFlight().get()->getFlightOperatorType() == FlightOperatorType::DOMESTIC)
        {
            result.emplace_back(std::ref(a->getFlightTicketAssociatedFlight().get()->getFlightAssociatedPlane()));
        }
    }
    if (result.empty())
    {
        throw std::runtime_error("NOT FOUND");
    }
    return result;
};

/*
    A function to find and return the airplane type with the highest flight ticket price value.
*/
std::function<AirPlaneType(Container &data)> AirPlaneTypeHighestTicketPrice = [](Container &data)
{
    if (data.empty())
    {
        throw std::runtime_error("list is empty!!");
    }
    float max = 0.0f;
    AirPlaneType res;
    for (auto &a : data)
    {
        if (a->getFlightTicketPrice() > max)
        {
            max = a->getFlightTicketPrice();
            res = a->getFlightTicketAssociatedFlight().get()->getFlightAssociatedPlane().get()->getAirPlaneType();
        }
    }
    return res;
};

/*
    A function to find and return all instances of airplane type for which flight ticket prices are above a given threshold value.
*/
std::function<AirplaneContainer(Container &data, float threshold)> AirPlaneInstanceAboveThreshold = [](Container &data, float threshold)
{
    if (data.empty())
    {
        throw std::runtime_error("list is empty!!");
    }
    AirplaneContainer result;
    for (auto &a : data)
    {
        if (a->getFlightTicketPrice() > threshold)
        {
            result.emplace_back(a->getFlightTicketAssociatedFlight().get()->getFlightAssociatedPlane());
        }
    }
    if (result.empty())
    {
        throw std::runtime_error("NOT FOUND");
    }
    return result;
};

/*
    A function to find and return the flight instances for the flight ticket whose flight ticket number is provided as an argument to the function.
*/
std::function<std::shared_ptr<Flight>(Container &data, std::string number)> FindByFlightTicketNumber = [](Container &data, std::string number)
{
    if (data.empty())
    {
        throw std::runtime_error("list is empty!!");
    }
    std::shared_ptr<Flight> res;
    bool flag = false;
    for (auto &a : data)
    {
        if (a->getFlightTicketNumber() == number)
        {
            res = a->getFlightTicketAssociatedFlight().get();
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        throw std::runtime_error("NUMBER NOT FOUND");
    }
    return res;
};

/*
    A function to find and return the airplane type of the associated flight instance for which the flight ticket number is provided as an argument to the function.
*/
std::function<AirPlaneType(Container &data, std::string number)> AirplaneTypeByTicketNumber = [](Container &data, std::string number)
{
    if (data.empty())
    {
        throw std::runtime_error("EMPTY");
    }
    AirPlaneType res;
    bool flag = false;
    for (auto &a : data)
    {
        if (a->getFlightTicketNumber() == number)
        {
            res = a->getFlightTicketAssociatedFlight().get()->getFlightAssociatedPlane().get()->getAirPlaneType();
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        throw std::runtime_error("NUMBER NOT FOUND");
    }
    return res;
};

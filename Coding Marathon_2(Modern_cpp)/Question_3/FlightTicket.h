#ifndef FLIGHTTICKETY_H
#define FLIGHTTICKETY_H

#include <iostream>
#include "FlightCategory.h"
#include "Flight.h"
#include <memory>

using Reference2 = std::reference_wrapper<std::shared_ptr<Flight>>;

class FlightTicket
{
private:
    /* data */
    std::string flightTicketNumber;
    FlightTicketCategory flightTicketCategory;
    Reference2 flightTicketAssociatedFlight;
    float flightTicketPrice;

public:
    FlightTicket(/* args */) = delete;
    FlightTicket(const FlightTicket &obj) = delete;
    FlightTicket(FlightTicket &&obj) = delete;
    FlightTicket(std::string number, FlightTicketCategory flightTicketCategory_, Reference2 associatedFlight, float price);
    ~FlightTicket();

    float getFlightTicketPrice() const { return flightTicketPrice; }
    void setFlightTicketPrice(float flightTicketPrice_) { flightTicketPrice = flightTicketPrice_; }

    Reference2 getFlightTicketAssociatedFlight() const { return flightTicketAssociatedFlight; }
    void setFlightTicketAssociatedFlight(const Reference2 &flightTicketAssociatedFlight_) { flightTicketAssociatedFlight = flightTicketAssociatedFlight_; }

    FlightTicketCategory getFlightTicketCategory() const { return flightTicketCategory; }
    void setFlightTicketCategory(const FlightTicketCategory &flightTicketCategory_) { flightTicketCategory = flightTicketCategory_; }

    std::string getFlightTicketNumber() const { return flightTicketNumber; }
    void setFlightTicketNumber(const std::string &flightTicketNumber_) { flightTicketNumber = flightTicketNumber_; }

    friend std::ostream &operator<<(std::ostream &os, const FlightTicket &rhs);
};

/*
    A function which returns the flight ticket category in string form.
*/
std::string DisplayFlightTicketCategory(FlightTicketCategory type);

#endif // FLIGHTTICKETY_H

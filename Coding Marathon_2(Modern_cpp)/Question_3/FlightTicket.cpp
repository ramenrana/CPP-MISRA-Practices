#include "FlightTicket.h"

/*
    A parametrized constructor for class flight ticket
*/
FlightTicket::FlightTicket(std::string number, FlightTicketCategory flightTicketCategory_,
                           Reference2 associatedFlight, float price)
    : flightTicketNumber(number), flightTicketCategory(flightTicketCategory_), flightTicketAssociatedFlight(associatedFlight),
      flightTicketPrice(price)
{
}

/*
    Destructor of class flightticket
*/
FlightTicket::~FlightTicket()
{
    std::cout << "FLIGHT TICKET DESTROYED\n";
}

/*
    AN overloaded operator << to display all the details of the calss flight ticket
*/
std::ostream &operator<<(std::ostream &os, const FlightTicket &rhs)
{
    os << "flightTicketNumber: " << rhs.flightTicketNumber
       << " flightTicketCategory: " << DisplayFlightTicketCategory(rhs.flightTicketCategory)
       << " flightTicketAssociatedFlight: " << rhs.flightTicketAssociatedFlight.get()
       << " flightTicketPrice: " << rhs.flightTicketPrice;
    return os;
}

/*
    A function to display flight ticket category
*/
std::string DisplayFlightTicketCategory(FlightTicketCategory type)
{
    if (type == FlightTicketCategory::BUSINESS)
    {
        return "BUSINESS";
    }
    else if (type == FlightTicketCategory::ECONOMY)
    {
        return "ECONOMY";
    }
    else
    {
        return "PREMIUM";
    }
}

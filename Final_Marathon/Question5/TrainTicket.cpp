#include "TrainTicket.h"


TrainTicket::TrainTicket(float price, TicketType tictype, TicketClass ticclass)
:ticketPrice(price), ticketType(tictype), ticketClass(ticclass)
{

}

std::ostream &operator<<(std::ostream &os, const TrainTicket &rhs) {
    os << "ticketPrice: " << rhs.ticketPrice
       << " ticketType: " << DisplayTicketType(rhs.ticketType)
       << " ticketClass: " << DisplayTicketClass(rhs.ticketClass);
    return os;
}

std::string DisplayTicketType(TicketType type)
{
    if(type == TicketType::GENERAL){return "GENERAL";}
    else if(type == TicketType::RESERVED){return "RESERVED";}
    else{
        return "WAITING";
    }
}


std::string DisplayTicketClass(TicketClass type)
{
    if(type == TicketClass::AC){return "AC";}
    else if(type == TicketClass::FIRST){return "FIRST";}
    else if(type == TicketClass::SECOND){return "SECOND";}
    else{
        return "SLEEPER";
    }
}
#include "TrainTicket.h"
std::ostream &operator<<(std::ostream &os, const TrainTicket &rhs) {
    os << "ticketPrice: " << rhs.ticketPrice
       << " ticketType: " <<DisplayTicketType( rhs.ticketType)
       << " ticketClass: " <<DisplayTicketClass( rhs.ticketClass);
    return os;
}
TrainTicket::TrainTicket(float ticketPrice, TicketType ticketType, TicketClass ticketClass)
:ticketPrice(ticketPrice),ticketType(ticketType),ticketClass(ticketClass){
}

std::string DisplayTicketType(TicketType type){
    if(TicketType::GENERAL==type){
        return "GENERAL";
    }else if(TicketType::RESERVED==type) {
        return "RESERVED";
    }else{
        return "WAITING";
    }
}

std::string DisplayTicketClass(TicketClass type){
    if(TicketClass::FIRST==type){
        return "FIRST";
    }else if(TicketClass::SECOND==type){
        return "SECOND";
    }else if(TicketClass::SLEEPER==type){
        return "SLEEPER";
    }else{
        return "AC";
    }
}

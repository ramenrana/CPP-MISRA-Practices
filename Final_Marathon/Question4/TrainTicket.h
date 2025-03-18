#ifndef TRAINTICKET_H
#define TRAINTICKET_H

#include <iostream>
#include "TicketClass.h"
#include "TicketType.h"

class TrainTicket
{
private:
    float ticketPrice;
    TicketType ticketType;
    TicketClass ticketClass;
    
public:
    TrainTicket(/* args */)=delete ;
    TrainTicket(TrainTicket &obj)=default;
    TrainTicket(TrainTicket &&obj)=delete;

    TrainTicket(
         float ticketPrice,
        TicketType ticketType,
        TicketClass ticketClass
    );

    ~TrainTicket() {}

    
    float getTicketPrice()  { return ticketPrice; }
    void setTicketPrice(float ticketPrice_) { ticketPrice = ticketPrice_; }

    TicketType getTicketType() const { return ticketType; }
    void setTicketType(const TicketType &ticketType_) { ticketType = ticketType_; }

    TicketClass getTicketClass() const { return ticketClass; }
    void setTicketClass(const TicketClass &ticketClass_) { ticketClass = ticketClass_; }

    friend std::ostream &operator<<(std::ostream &os, const TrainTicket &rhs);
    
};

std::string DisplayTicketType(TicketType type);

std::string DisplayTicketClass(TicketClass type);

#endif // TRAINTICKET_H

#ifndef TRAINTICKET_H
#define TRAINTICKET_H

#include <iostream>
#include "TicketClass.h"
#include "TicketType.h"

class TrainTicket
{
private:
    float ticketPrice;
    TicketType  ticketType;
    TicketClass ticketClass;

public:
    TrainTicket() = delete;
    TrainTicket(const TrainTicket& obj) = delete;
    TrainTicket(TrainTicket&& obj) = delete;
    TrainTicket(float price, TicketType tictype, TicketClass ticclass);
    ~TrainTicket() = default;

    float getTicketPrice() const { return ticketPrice; }
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
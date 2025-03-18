#include "Train.h"

std::ostream &operator<<(std::ostream &os, const Train &rhs) {
    os << "trainNumber: " << rhs.trainNumber
       << " trainStartingStation: " << rhs.trainStartingStation
       << " trainDestinationStation: " << rhs.trainDestinationStation
       << " trainDepartureHour: " << rhs.trainDepartureHour
       << " trainDepartureMinute: " << rhs.trainDepartureMinute
       << " trainBookTickets: " ;
       for(auto& a : rhs.trainBookTickets){
        std::cout << * a << "\n";
       }
    return os;
}

Train::Train(std::string number, std::string startStation, std::string endStation, int hour, int minute, TicketContainer tickets)
:trainNumber(number),trainStartingStation(startStation),trainDestinationStation(endStation),trainBookTickets(tickets)
{
    if(hour > 0 && hour <= 23){
        this->trainDepartureHour = hour;
    }
    if(minute > 0 && minute <= 59){
        this->trainDepartureMinute = minute;
    }
}
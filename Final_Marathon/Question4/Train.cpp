#include "Train.h"
std::ostream &operator<<(std::ostream &os, const Train &rhs) {
    os << "trainNumber: " << rhs.trainNumber
       << " trainStartingStation: " << rhs.trainStartingStation
       << " trainDestinationStation: " << rhs.trainDestinationStation
       << " trainDepartureMinute: " << rhs.trainDepartureMinute
       << " trainBookedTickets: ";
       for(auto &val :rhs.trainBookedTickets){
        os<<*val.get();
       }
        
    return os;
}
Train::Train(std::string trainNumber, std::string trainStartingStation, std::string trainDestinationStation,int trainDepartureHour, int trainDepartureMinute, ContainerBookTicket trainBookedTickets)
:trainNumber(trainNumber),trainStartingStation(trainStartingStation),trainDestinationStation(trainDestinationStation){
    
    if(trainDepartureHour>0 && trainDepartureHour<23){
        this->trainDepartureHour=trainDepartureHour;
    }else{
        std::runtime_error("Error!!");
    }
    if(trainDepartureMinute>0 && trainDepartureMinute<59){
        this->trainDepartureMinute=trainDepartureMinute;
    }else{
        std::runtime_error("Error!!");
    }

    this->trainBookedTickets=trainBookedTickets;
}

#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
#include <list>
#include <memory>
#include "TrainTicket.h"

using ContainerBookTicket =std::list<std::shared_ptr<TrainTicket>>;
class Train
{
private:
    std::string trainNumber;
    std::string trainStartingStation;
    std::string trainDestinationStation;
    int trainDepartureHour;
    int trainDepartureMinute;
    ContainerBookTicket trainBookedTickets;

public:
    Train(/* args */)=delete;
    Train(Train &obj)=default;
    Train(Train &&obj)=delete;
    Train(
        std::string trainNumber,
        std::string trainStartingStation,
        std::string trainDestinationStation,
        int trainDepartureHour,
        int trainDepartureMinute,
        ContainerBookTicket trainBookedTickets
    );
    ~Train()=default;

    int getTrainDepartureHour() const { return trainDepartureHour; }
    void setTrainDepartureHour(int trainDepartureHour_) { trainDepartureHour = trainDepartureHour_; }

    std::string getTrainNumber() const { return trainNumber; }
    void setTrainNumber(const std::string &trainNumber_) { trainNumber = trainNumber_; }

    std::string getTrainStartingStation() const { return trainStartingStation; }
    void setTrainStartingStation(const std::string &trainStartingStation_) { trainStartingStation = trainStartingStation_; }

    std::string getTrainDestinationStation() const { return trainDestinationStation; }
    void setTrainDestinationStation(const std::string &trainDestinationStation_) { trainDestinationStation = trainDestinationStation_; }

    int getTrainDepartureMinute() const { return trainDepartureMinute; }
    void setTrainDepartureMinute(int trainDepartureMinute_) { trainDepartureMinute = trainDepartureMinute_; }

    ContainerBookTicket getTrainBookedTickets() const { return trainBookedTickets; }
    void setTrainBookedTickets(const ContainerBookTicket &trainBookedTickets_) { trainBookedTickets = trainBookedTickets_; }

    friend std::ostream &operator<<(std::ostream &os, const Train &rhs);
    
};

#endif // TRAIN_H

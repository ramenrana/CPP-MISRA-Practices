#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
#include "TrainTicket.h"
#include <vector>
#include <memory>

using TicketContainer = std::vector<std::shared_ptr<TrainTicket>>;

class Train
{
private:
    std::string trainNumber;
    std::string trainStartingStation;
    std::string trainDestinationStation;
    int trainDepartureHour;
    int trainDepartureMinute;
    TicketContainer trainBookTickets;
public:
    /// @brief Default Constructor is Disabled
    Train() = delete;

    /// @brief Copy Constuctor is Disabled
    /// @param obj 
    Train(const Train& obj) = delete;

    /// @brief Move Construct deleted
    /// @param obj 
    Train(Train&& obj) = delete;
    Train(std::string number, std::string startStation, std::string endStation,int hour, int minute,TicketContainer tickets);
    ~Train() = default;

    std::string getTrainNumber() const { return trainNumber; }
    void setTrainNumber(const std::string &trainNumber_) { trainNumber = trainNumber_; }

    std::string getTrainStartingStation() const { return trainStartingStation; }
    void setTrainStartingStation(const std::string &trainStartingStation_) { trainStartingStation = trainStartingStation_; }

    std::string getTrainDestinationStation() const { return trainDestinationStation; }
    void setTrainDestinationStation(const std::string &trainDestinationStation_) { trainDestinationStation = trainDestinationStation_; }

    int getTrainDepartureHour() const { return trainDepartureHour; }
    void setTrainDepartureHour(int trainDepartureHour_) { trainDepartureHour = trainDepartureHour_; }

    int getTrainDepartureMinute() const { return trainDepartureMinute; }
    void setTrainDepartureMinute(int trainDepartureMinute_) { trainDepartureMinute = trainDepartureMinute_; }

    TicketContainer getTrainBookTickets() const { return trainBookTickets; }
    void setTrainBookTickets(const TicketContainer &trainBookTickets_) { trainBookTickets = trainBookTickets_; }

    friend std::ostream &operator<<(std::ostream &os, const Train &rhs);

};


#endif // TRAIN_H
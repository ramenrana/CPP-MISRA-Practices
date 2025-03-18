#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include "PassengerType.h"
#include <variant>
class Passenger
{
private:
    std::variant<std::string,int> passengerId;
    std::string passengerName;
    int passengerAge;
    PassengerType passengerType;
    float passengerFare;
public:
    /// @brief Default constructor deleted
    Passenger(/* args */)=delete;

    /// @brief Copy Constructor enabled
    Passenger(Passenger &obj)=default;

    /// @brief Move Constructor Deleted
    Passenger(Passenger&& obj)=delete;

    /// @brief Parameterized Constructor
    Passenger(
        std::variant<std::string,int> passengerId,
        std::string passengerName,
        int passengerAge,
        PassengerType passengerType,
        float passengerFare
    );

    /// @brief Destructor
    ~Passenger() ;

    /// @brief Getter Setter Functions 
 
    std::variant<std::string,int> getPassengerId() const { return passengerId; }
    void setPassengerId(const std::variant<std::string,int> &passengerId_) { passengerId = passengerId_; }

    int getPassengerAge() const { return passengerAge; }
    void setPassengerAge(int passengerAge_) { passengerAge = passengerAge_; }

    PassengerType getPassengerType() const { return passengerType; }
    void setPassengerType(const PassengerType &passengerType_) { passengerType = passengerType_; }

    float getPassengerFare() const { return passengerFare; }
    void setPassengerFare(float passengerFare_) { passengerFare = passengerFare_; }

    std::string getPassengerName() const { return passengerName; }
    void setPassengerName(const std::string &passengerName_) { passengerName = passengerName_; }

    /// @brief Overload << operator 
    /// @param os 
    /// @param rhs 
    /// @return ostream
    friend std::ostream &operator<<(std::ostream &os, const Passenger &rhs);

    
};

/// @brief Dislay Enum 
std::string DisplayEnum(PassengerType type);

#endif // PASSENGER_H

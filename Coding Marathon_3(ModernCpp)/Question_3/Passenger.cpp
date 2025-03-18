#include "Passenger.h"
std::ostream &operator<<(std::ostream &os, const Passenger &rhs) {
    os << "passengerId: ";
    std::visit([&](auto &&obj){os<<obj;},rhs.passengerId); 
       os<< " passengerName: " << rhs.passengerName
       << " passengerAge: " << rhs.passengerAge
       << " passengerType: " <<DisplayEnum( rhs.passengerType)
       << " passengerFare: " << rhs.passengerFare;
    return os;
}
std::string DisplayEnum(PassengerType type)
{
    if(PassengerType::PREMIMUM==type){
        return "PREMIMUM";
    }else if(PassengerType::REGULAR==type){
        return "REGULAR";
    }else{
        return "VIP";
    }
}

Passenger::Passenger(std::variant<std::string, int> passengerId, std::string passengerName, int passengerAge, PassengerType passengerType, float passengerFare)
:passengerId(passengerId),passengerName(passengerName){
    if(passengerAge>0 && passengerAge<=150){
        this->passengerAge=passengerAge;
    }else{
        std::runtime_error("Invalid Age!!");
    }

    this->passengerType=passengerType;
    this->passengerFare=passengerFare;
}

Passenger::~Passenger()
{
    std::cout<<"Passenger Deleted\n";
}

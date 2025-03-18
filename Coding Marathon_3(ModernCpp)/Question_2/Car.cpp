#include "Car.h"
std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "carPrice: " << rhs.Price
       << " Brand: " << rhs.Brand
       << " VehicleType: " <<DisplayEnum( rhs.VehicleType)
       << " carSeatCount: " << rhs.carSeatCount;
    return os;
}

std::string DisplayEnum(RiddingType type)
{
    if(RiddingType::COMMUTE==type){
        return "COMMUTE";
    }else if(RiddingType::PASSENGER==type){
        return "PASSENGER";
    }else if(RiddingType::UTILITY==type){
        return "UTILITY";

    }else{
        return "SPORTS";
    }
}

Car::Car(float Price, std::string Brand, RiddingType VehicleType, int carSeatCount)
:Price(Price),Brand(Brand),VehicleType(VehicleType){
    if(carSeatCount>=2 && carSeatCount<=7){
        this->carSeatCount=carSeatCount;
    }else{
        std::runtime_error("CarSeatCount Should be between 2 and 7!!!");
    }
}

Car::~Car()
{
    std::cout<<"Car DELETED";
}

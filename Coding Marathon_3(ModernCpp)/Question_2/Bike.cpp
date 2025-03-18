#include "Bike.h"



std::string DisplayBikeEnum(RiddingType type)
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

Bike::Bike(float Price, std::string Brand, RiddingType BikeVehicleType, int bikeSeatCount)
:Price(Price),VehicleType(VehicleType){
    if(bikeSeatCount==1 || bikeSeatCount==2){
        this->bikeSeatCount=bikeSeatCount;
    }else{
        std::runtime_error("Bike Seat count should be 1 or 2!!");
    }
}
Bike::~Bike()
{
    std::cout<<"Bike Deleted\n";
}

std::ostream &operator<<(std::ostream &os, const Bike &rhs) {
    os << "Price: " << rhs.Price
       << " Brand: " << rhs.getBrand()
       << " VehicleType: " <<DisplayBikeEnum(rhs.VehicleType)
       << " bikeSeatCount: " << rhs.bikeSeatCount;
    return os;
}

#include "ElectricVehicle.h"
std::ostream &operator<<(std::ostream &os, const ElectricVehicle &rhs) {
    os << "_evType: " <<DisplayEnumEV(rhs._evType)
       << " _evPrice: " << rhs._evPrice
       << " _evBrand: " << rhs._evBrand
       << " _evSeatCount: " << rhs._evSeatCount;
    return os;/// @brief Display Enum
}
std::string DisplayEnumEV(VehicleType type)
{
    if(VehicleType::DIESEL==type){
        return "DIESEL";
    }else if(VehicleType::PETROL==type){
        return "PETROL";
    }else if(VehicleType::PETROL_HYBRID==type){
        return "PETROL_HYBRID";
    }else if(VehicleType::REGULAR==type){
        return "REGULAR";
    }else{
        return "UTILITY";
    }
}
ElectricVehicle::ElectricVehicle(VehicleType _evType, float _evPrice, std::string _evBrand, int _evSeatCount)
:_evType(_evType),_evPrice(_evPrice),_evBrand(_evBrand){
    if(_evSeatCount>=2 && _evSeatCount<=6){
        this->_evSeatCount=_evSeatCount;
    }else{
        std::runtime_error("WRong Input for Seat count!!");
    }
}

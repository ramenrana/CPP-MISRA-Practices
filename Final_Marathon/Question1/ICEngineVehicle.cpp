#include "ICEngineVehicle.h"
std::ostream &operator<<(std::ostream &os, const ICEngineVehicle &rhs) {
    os << "_icType: " << DisplayEnumICEV(rhs._icType)
       << " _icPrice: " << rhs._icPrice
       << " _icBrand: " << rhs._icBrand
       << " _icSeatCount: " << rhs._icSeatCount;
    return os;
}
std::string DisplayEnumICEV(VehicleType type)
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

ICEngineVehicle::ICEngineVehicle(VehicleType _icType, float _icPrice, std::string _icBrand, int _icSeatCount)
:_icType(_icType),_icPrice(_icPrice),_icBrand(_icBrand){
    if(_icSeatCount>=2 && _icSeatCount<=6){
        this->_icSeatCount=_icSeatCount;
    }else{
        std::runtime_error("WRong Input for Seat count!!");
    }
}

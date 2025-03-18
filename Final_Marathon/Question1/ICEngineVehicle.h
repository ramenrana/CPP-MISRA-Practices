#ifndef ICENGINEVEHICLE_H
#define ICENGINEVEHICLE_H

#include <iostream>
#include "VehicleType.h"

class ICEngineVehicle
{
private:
    VehicleType _icType;
    float _icPrice;
    std::string _icBrand;
    int _icSeatCount;
public:
    /// @brief Default Constructor is disbled
    ICEngineVehicle()=delete;

    /// @brief Copy Constructor is disbled
    /// @param obj 
    ICEngineVehicle(ICEngineVehicle &obj)=default;
    
    /// @brief Move Constructor is disbled
    /// @param obj 
    ICEngineVehicle(ICEngineVehicle &&obj)=delete;
    
    /// @brief Parameterized Constructor
    /// @param _evType 
    /// @param _evPrice 
    /// @param _evBrand 
    /// @param _evSeatCount
    ICEngineVehicle(
        VehicleType _icType,
    float _icPrice,
    std::string _icBrand,
    int _icSeatCount
    );

    /// @brief Default Destructor
    ~ICEngineVehicle()=default;

    /// @brief Getter Setter Function
    VehicleType Type() const { return _icType; }
    void setIcType(const VehicleType &icType) { _icType = icType; }

    float Price() const { return _icPrice; }
    void setIcPrice(float icPrice) { _icPrice = icPrice; }

    std::string Brand() const { return _icBrand; }
    void setIcBrand(const std::string &icBrand) { _icBrand = icBrand; }

    int SeatCount() const { return _icSeatCount; }
    void setIcSeatCount(int icSeatCount) { _icSeatCount = icSeatCount; }

    /// @brief Overload OStream Operator<< 
    /// @param os 
    /// @param rhs 
    /// @return ostream
    friend std::ostream &operator<<(std::ostream &os, const ICEngineVehicle &rhs);

    
};
/// @brief Display Enum
std::string DisplayEnumICEV(VehicleType type);
#endif // ICENGINEVEHICLE_H

#ifndef ELECTRICVEHICLE_H
#define ELECTRICVEHICLE_H

#include <iostream>
#include "VehicleType.h"

class ElectricVehicle
{
private:
    VehicleType _evType;
    float _evPrice;
    std::string _evBrand;
    int _evSeatCount;
public:
    /// @brief Default Constructor is disbled
    ElectricVehicle()=delete;
    /// @brief Copy Constructor is disbled
    /// @param obj 
    ElectricVehicle(ElectricVehicle &obj)=delete;
    /// @brief Move Constructor is disbled
    /// @param obj 
    ElectricVehicle(ElectricVehicle &&obj)=delete;

    /// @brief Parameterized Constructor
    /// @param _evType 
    /// @param _evPrice 
    /// @param _evBrand 
    /// @param _evSeatCount 
    ElectricVehicle(
        VehicleType _evType,
        float _evPrice,
        std::string _evBrand,
        int _evSeatCount
        );

    /// @brief Default Destructor
    ~ElectricVehicle()=default;

    /// @brief Getter Setter Function

    VehicleType Type() const { return _evType; }
    void setEvType(const VehicleType &evType) { _evType = evType; }

    float Price() const { return _evPrice; }
    void setEvPrice(float evPrice) { _evPrice = evPrice; }

    std::string Brand() const { return _evBrand; }
    void setEvBrand(const std::string &evBrand) { _evBrand = evBrand; }

    int SeatCount() const { return _evSeatCount; }
    void setEvSeatCount(int evSeatCount) { _evSeatCount = evSeatCount; }

    /// @brief Overload OStream Operator<< 
    /// @param os 
    /// @param rhs 
    /// @return ostream
    friend std::ostream &operator<<(std::ostream &os, const ElectricVehicle &rhs);
    
};
/// @brief Display Enum
std::string DisplayEnumEV(VehicleType type);

#endif // ELECTRICVEHICLE_H

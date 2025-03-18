#ifndef BIKE_H
#define BIKE_H

#include <iostream>
#include "RiddingType.h"

class Bike
{
private:
    float Price;
    std::string Brand;
    RiddingType VehicleType;
    int bikeSeatCount;
public:
    /// @brief Default Constructor Disable
    Bike(/* args */)=delete;

    /// @brief Copy Constructor Enabled
    Bike(Bike &obj)=default;

    /// @brief Move Constructor Disabled
    Bike(Bike &&obj)=delete;

    /// @brief Parameterize Constructor
    Bike(
        float Price,
        std::string Brand,
        RiddingType VehicleType,
        int bikeSeatCount
    );

    /// @brief Destructor
    ~Bike();

    /// @brief Getter Setter Function

    float getPrice() const { return Price; }
    void setPrice(float Price_) { Price = Price_; }

    std::string getBrand() const { return Brand; }
    void setBrand(const std::string &_Brand) { Brand = _Brand; }

    RiddingType getVehicleType() const { return VehicleType; }
    void setVehicleType(const RiddingType &_VehicleType) { VehicleType = _VehicleType; }

    int getBikeSeatCount() const { return bikeSeatCount; }
    void setBikeSeatCount(int bikeSeatCount_) { bikeSeatCount = bikeSeatCount_; }

    

    /// @brief Overload Ostream << for Display the Object
    /// @param os 
    /// @param rhs 
    /// @return std::ostream
    friend std::ostream &operator<<(std::ostream &os, const Bike &rhs);

        
};
/// @brief Display Enum
std::string DisplayBikeEnum(RiddingType type); 

#endif // BIKE_H

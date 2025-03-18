#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "RiddingType.h"

class Car
{
private:
    float Price;
    std::string Brand;
    RiddingType VehicleType;
    int carSeatCount;
public:
    /// @brief Default Constructor Disable
    Car()=delete;

    /// @brief Copy Constructor Enabled
    Car(Car &obj)=default;

    /// @brief Move Constructor Disabled
    Car(Car &&obj)=delete;

    /// @brief Parameterize Constructor
    Car(
        float Price,
        std::string Brand,
        RiddingType VehicleType,
        int carSeatCount
    );

    /// @brief Destructor
    ~Car();

    /// @brief Getter Setter Function
    float getPrice() const { return Price; }
    void setPrice(float Price_) { Price = Price_; }

    std::string getBrand() const { return Brand; }
    void setBrand(const std::string &Brand_) { Brand = Brand_; }

    RiddingType getVehicleType() const { return VehicleType; }
    void setVehicleType(const RiddingType &VehicleType_) { VehicleType = VehicleType_; }

    int getCarSeatCount() const { return carSeatCount; }
    void setCarSeatCount(int carSeatCount_) { carSeatCount = carSeatCount_; }

    /// @brief Overload Ostream << for Display the Object
    /// @param os 
    /// @param rhs 
    /// @return std::ostream
    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

};

/// @brief Display Enum
std::string DisplayEnum(RiddingType type); 

#endif // CAR_H

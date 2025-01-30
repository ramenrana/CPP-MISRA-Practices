#ifndef CAR_H
#define CAR_H

#include "CarbonFootprint.h"

class Car : public CarbonFootprint
{
private:
    double milesDriven; /* in miles */
    double fuelEfficiency; /* in miles per gallon (mpg) */
public:
    Car(/* args */) = default;
    Car(double, double);
    virtual ~Car() = default;
    virtual double getCarbonFootprint() const override;

    double getMilesDriven() const { return milesDriven; }
    void setMilesDriven(double milesDriven_) { milesDriven = milesDriven_; }

    double getFuelEfficiency() const { return fuelEfficiency; }
    void setFuelEfficiency(double fuelEfficiency_) { fuelEfficiency = fuelEfficiency_; }
};


#endif // CAR_H

#ifndef BUILDING_H
#define BUILDING_H
#include "CarbonFootprint.h"

class Building:public CarbonFootprint
{
private:
    double electricityUsage; /* in kWh */
    double fuelUsage; /* in gallons; */ 
public:
    Building() = default;
    Building(double, double);
    virtual ~Building() = default;
    virtual double getCarbonFootprint() const override;

    double getElectricityUsage() const { return electricityUsage; }
    void setElectricityUsage(double electricityUsage_) { electricityUsage = electricityUsage_; }

    double getFuelUsage() const { return fuelUsage; }
    void setFuelUsage(double fuelUsage_) { fuelUsage = fuelUsage_; }
};





#endif // BUILDING_H

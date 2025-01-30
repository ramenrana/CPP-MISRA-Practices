#include "Car.h"

Car::Car(double mils, double fuelEff)
{
    this->milesDriven = mils;
    this->fuelEfficiency = fuelEff;
}

double Car::getCarbonFootprint() const
{
    const double fuel_emm_fac = 8.89; /* kg CO2 per gallon */
    double fuelConsumed = milesDriven / fuelEfficiency; /* gallons */
    return fuelConsumed * fuel_emm_fac;
}

#include "Building.h"

Building::Building(double e_use, double f_use)
{
    this->electricityUsage = e_use;
    this->fuelUsage = f_use;
}

double Building::getCarbonFootprint() const
{
    const double electric_emmi_fac = 0.5; /* kg CO2 per kWh */
    const double fuel_emmi_fac = 2.5; /* kg CO2 per gallon */
        
    return (electricityUsage * electric_emmi_fac) + 
               (fuelUsage * fuel_emmi_fac);
}

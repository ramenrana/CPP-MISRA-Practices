#include <iostream>
#include <vector>
#include "Car.h"
#include "Building.h"
#include "Bicycle.h"

int main(void) {
    const double electricityUsage = 1000.00;
    const double fuelUsage = 100.00;
    Building building (electricityUsage, fuelUsage);
    
    const double milesDriven = 2000.00;
    const double fuelEfficiency = 20.00; 
    Car car(milesDriven, fuelEfficiency);

    const double caloriesBurned = 3000.00; 
    Bicycle Bicycle(caloriesBurned);

    std::vector<CarbonFootprint*> footprint;
    footprint.push_back(&building);
    footprint.push_back(&car);
    footprint.push_back(&Bicycle);

    for (const auto &value : footprint){
        std::cout<<value->getCarbonFootprint()<<std::endl;
    }

}
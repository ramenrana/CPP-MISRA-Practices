#include "Bicycle.h"

Bicycle::Bicycle(double cal_burned)
{
    this->caloriesBurned = cal_burned;
}

double Bicycle::getCarbonFootprint() const
{
    const double cal_emm_fac = 0.001; /*kg CO2 per calorie*/
    return caloriesBurned * cal_emm_fac;
}

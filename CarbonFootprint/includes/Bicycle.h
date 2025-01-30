#ifndef BICYCLE_H
#define BICYCLE_H

#include "CarbonFootprint.h"

class Bicycle : public CarbonFootprint
{
private:
    double caloriesBurned; /* in calories */
public:
    Bicycle(/* args */) = default;
    Bicycle(double);
    virtual ~Bicycle() = default;
    virtual double getCarbonFootprint() const override;

    double getCaloriesBurned() const { return caloriesBurned; }
    void setCaloriesBurned(double caloriesBurned_) { caloriesBurned = caloriesBurned_; }
};


#endif // BICYCLE_H

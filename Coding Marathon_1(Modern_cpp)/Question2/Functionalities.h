#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include "Engine.h"
#include "EngineType.h"
#include "Car.h"
#include "CarType.h"
#include <memory>
#include <list>
#include <functional>

using Pointer = std::unique_ptr<Car>;
using Container= std::list<Pointer>;


//Create an list of Car Object
void CreateObject(Container &data);


//Return Engine Horse Power whose carId is Matched

std::string EngineHorsePowerWithCarId(Container &data, std::string carId);


//return all instances of car whose engine Torque is >80
std::optional<std::list<Car*> > EngineTorque(Container &data);

//return Instances of all car whose carType is  matched

std::optional<std::list<Car*> > AllCarWithMatchingType(Container &data, carType type);

//Return average of engineHorsePower whose engineType is ICT and carPrice >1000000

float AverageEngineHorsePower(Container &data);

// Find CarId of the Car with Lowest car Price
void CarIdwithLowestCarPrice(Container &data);

//Add Two CarPrice
float CarPrice(Car& ob1, Car &ob2);

//Check The Container Empty or Not
bool Check(Container &data);

#endif // FUNCTIONALITIES_H

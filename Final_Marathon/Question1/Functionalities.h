#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <variant>
#include <iostream>
#include "ElectricVehicle.h"
#include "VehicleType.h"
#include "ICEngineVehicle.h"
#include <list>
#include <memory>
#include <variant>

using EVPointer = std::unique_ptr<ElectricVehicle>;
using ICPointer = std::unique_ptr<ICEngineVehicle>;
using Container = std::list<std::variant<EVPointer,ICPointer>>;

/*Create Object of Both Type ElectricVehicle and ICEngineVehicle*/
void CreateObject(Container &data);

/*Find Average of all price in container*/
void AveragePrice(Container &data);

/*Find Lowest Price In the Container and print Brand*/
void LowestPrice(Container &data);

/* Find Out all vehicle whose price below threshold */

bool BelowThreshold(Container &data,float threshold);

/* Check At least N instances in container match  folloowing Condition
    - VehicleType Match 
    -Vehicle Seat Count Match 
*/
void Check_with_Type_SeatCount(Container &data,VehicleType type, int count);

/* Demonstration All Funtionalities */
void Demonstrate();

#endif // FUNCTIONALITIES_H

#ifndef FUNCTIONALITES_H
#define FUNCTIONALITES_H

#include <iostream>
#include "Car.h"
#include "Bike.h"
#include "RiddingType.h"
#include <memory>
#include <list>
#include <optional>
#include <variant>

using BikePointer =std::shared_ptr<Bike>;
using CarPointer =std::shared_ptr<Car>;
using Container = std::list<std::variant<BikePointer,CarPointer>>;


/*
    Create list object of either Car or Bike
*/

void CreateObject(Container &data);


/*
    Find And Return Brand Of the Car or Price instances whose price is maximum
*/
std::variant<std::string,float> FindReturnBrandORPriceWhosePriceIsMax(Container &data);

/*
    Find And Return average price for all car 
*/
float FindAndReturnAverage( Container &data);

/* 
    Find and Return a container of a vehicleType whose price is below treshold
*/
std::optional<Container> FindReturnVehicleTypeBelowThreshold(Container &data,float threshold);

/*
    Return a boolean value if VehicleType is match
*/
bool MatchVehicleType(Container &data,RiddingType type);

/*
    Templte function that accept any container with car and Bike and print all whose brand instances matched
*/

template<typename T>
void DisplayAnyContainer(T &data,std::string brand){
        for(auto &val: data){
        std::visit([&](auto &&val1){
                  if((*val1).getBrand()==brand){
                    std::cout<<*val1;
                  }
        ;},val);
    }
}

/*
    Demonstrate All Functionalities
*/
void Demonstrate();
#endif // FUNCTIONALITES_H

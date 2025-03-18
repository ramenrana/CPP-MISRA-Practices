#include "Functionalites.h"

/*
    Create list object of either Car or Bike
*/

void CreateObject(Container &data)
{
    data.emplace_back(std::make_shared<Car>(1000.00f,"MARUTI",RiddingType::COMMUTE,3));
    data.emplace_back(std::make_shared<Car>(2000.00f,"BMW",RiddingType::PASSENGER,4));
    data.emplace_back(std::make_shared<Bike>(3000.0f,"BMW",RiddingType::SPORTS,1));
   
}

/*
    Find And Return Brand Of the Car or Price instances whose price is maximum
*/
std::variant<std::string, float> FindReturnBrandORPriceWhosePriceIsMax(Container &data)
{
    float max=0.0f;
    std::string brand;
    float price;
    for(auto &val: data){
        std::visit([&](auto &&val1){
            if((*val1).getPrice()>max){
                  max= (*val1).getPrice();
                  brand=(*val1).getBrand();
                  price=(*val1).getPrice();

            }
        ;},val);
    }
    return brand,price;
}

/*
    Find And Return average price for all car 
*/

float FindAndReturnAverage(Container &data)
{
    float total=0.0f;
    int count=0;
    for(auto &val: data){
        std::visit([&](auto &&val1){
                  total+= (*val1).getPrice();
                  count ++;
        ;},val);
    }
    return total/count;
}

/* 
    Find and Return a container of a vehicleType whose price is below treshold
*/
std::optional<Container> FindReturnVehicleTypeBelowThreshold(Container &data,float threshold)
{
    if(data.empty()){
        return {};
    }
    Container res;
    
    for(auto &val: data){
        std::visit([&](auto &&val1){
                  if((*val1).getPrice()<threshold){
                    res.emplace_back(val);
                  }
        ;},val);
    }

    if(res.empty()){
        return {};
    }else{
        return res;
    }

}

/*
    Return a boolean value if VehicleType is match
*/
bool MatchVehicleType(Container &data,RiddingType type){
    int flag=0;
    for(auto &val: data){
        std::visit([&](auto &&val1){
                  if((*val1).getVehicleType()==type){
                    flag=1;
                  }
        ;},val);
    }
    if(flag==1){
        return true;
    }else{
        return false;
    }
}
/*
    Demonstrate All Functionalities
*/

void Demonstrate()
{
    Container data;
    CreateObject(data);
    for(auto &val:data){
        std::visit([](auto &&val1){std::cout<<*val1;},val);
    }

    std::variant<std::string,float> res= FindReturnBrandORPriceWhosePriceIsMax(data);

    std::visit([](auto &&val){
        std::cout<<val;
    },res);

    std::optional<Container> res1= FindReturnVehicleTypeBelowThreshold(data,200.0f);
    if(res1.has_value()){
        for(auto &val:res1.value()){
            std::visit([](auto &&val1){std::cout<<*val1;},val);
        }
    }else{
        std::cout<<"Result not found";
    }
    
    DisplayAnyContainer<>(data,"MARUTI");
}

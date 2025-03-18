#include "Functionalities.h"
#include "algorithm"
#include "numeric"
void CreateObject(Container &data)
{
    data.emplace_back(std::make_unique<ElectricVehicle>(VehicleType::DIESEL,100000.0f,"XXX",3));
    data.emplace_back(std::make_unique<ElectricVehicle>(VehicleType::PETROL_HYBRID,200000.0f,"YYYY",3));
    data.emplace_back(std::make_unique<ICEngineVehicle>(VehicleType::REGULAR,30000.0f,"AAA",4));
    data.emplace_back(std::make_unique<ICEngineVehicle>(VehicleType::PETROL_HYBRID,40000.0f,"BBB",4));
}

void AveragePrice(Container &data)
{
    float res = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [](float total,auto &ptr){
            return std::visit([&](auto &&val){
                 return val->Price()+total;
                 },ptr);
            }
    );

    std::cout<<"Average Price: "<<res/data.size();

}

void LowestPrice(Container &data)
{
    auto itr = std::min_element(
        data.begin(),
        data.end(),
        [](auto &ptr,auto &ptr1){
            return std::visit([&](auto &&val,auto &&val1){
                return val->Price() < val1->Price();
            },ptr,ptr1);
        }
    );
    std::visit([&](auto &&val){std::cout<<val->Brand();},*itr);

}

bool BelowThreshold(Container &data, float threshold)
{
    return std::all_of(
        data.begin(),
        data.end(),
        [&](auto &ptr){
            return std::visit([&](auto &&val){
                return val->Price()<threshold;
            },ptr);
        }
        );
}

void Check_with_Type_SeatCount(Container &data, VehicleType type, int count)
{
    int c=std::count_if(
        data.begin(),
        data.end(),
        [&](auto &ptr){
            return std::visit([&](auto &&val){
                return val->Type()==type && val->SeatCount()==count;
            },ptr);
        }
        );
        std::cout<<c;
}

void Demonstrate()
{
    Container data;
    CreateObject(data);
    for(auto &val:data){
        std::visit([](auto &&val1){std::cout<<*val1;},val);
    }
    AveragePrice(data);
    //std::cout<<"\n========\n";
    LowestPrice(data);

   std::cout<<BelowThreshold(data,150000.0f);

   Check_with_Type_SeatCount(data,VehicleType::DIESEL,3);
}

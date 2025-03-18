#include "Functionalities.h"
#include <algorithm>
#include <numeric>

//Check The Container Empty or Not
bool Check(Container &data)
{
    if(data.empty()){
        return true;
    }
    return false;
}

//Create an list of Car Object
void CreateObject(Container &data)
{
    data.emplace_back(std::make_unique<Car>(
        "101",
        "Maruti",
        carType::HATCHBACK,
        std::make_unique<Engine>("1",EngineType::HYBRID,67,76),
        656576.87f
    ));


    data.emplace_back(std::make_unique<Car>(
        "102",
        "Honda",
        carType::SEDAN,
        std::make_unique<Engine>("2",EngineType::ICT,59,78),
        1000000.87f
    ));


    data.emplace_back(std::make_unique<Car>(
        "102",
        "BMW",
        carType::HATCHBACK,
        std::make_unique<Engine>("1",EngineType::HYBRID,67,76),
        878676.87f
    ));


    data.emplace_back(std::make_unique<Car>(
        "104",
        "Macetezz",
        carType::SUV,
        std::make_unique<Engine>("2",EngineType::ICT,59,78),
        100870.87f
    ));
}


//Return Engine Horse Power whose carId is Matched
std::string EngineHorsePowerWithCarId(Container &data, std::string carId)
{
    if(Check(data)){
        std::runtime_error("Empty Container");
    }
    for (auto i = data.begin(); i != data.end(); i++)
    {
        if((**i).getCarId()==carId){
            return (**i).getCarId();
        }
    }
    
    return "NULL";
}

//return all instances of car whose engine Torque is >80
std::optional<std::list<Car*> > EngineTorque(Container &data)
{
    if(Check(data)){
        std::runtime_error("Empty Container");
    }
    std::list<Car*> data1(data.size());
    // for (auto i = data.begin(); i != data.end(); i++)
    // {
    //     if((**i).getEngine()->getEngineTorque()>80){
    //         data1.emplace_back((*i).get());
    //     }
    // }

    auto itr=std::copy_if(
        data.begin(),
        data.end(),
        data1.begin(),
        [](Pointer &p){p->getEngine()->getEngineTorque()>80;}
    );

    data1.resize(std::distance(data1.begin(),itr));
    
    if(data1.empty()){
        return {};
    }else{
        return data1;
    }
    
}

//return Instances of all car whose carType is  matched
std::optional<std::list<Car*> > AllCarWithMatchingType(Container &data, carType type)
{
    if(Check(data)){
        std::runtime_error("Empty Container");
    }
    std::list<Car*> data1;
    for (auto i = data.begin(); i != data.end(); i++)
    {
        if((**i).cARTYPE()==type){
            data1.emplace_back((*i).get());
        }
    }
    
    if(data1.empty()){
        return {};
    }else{
        return data1;
    }

}

//Return average of engineHorsePower whose engineType is ICT and carPrice >1000000
float AverageEngineHorsePower(Container &data)
{
    float total;
    int count =0;
    if(Check(data)){
        std::runtime_error("Empty Container");
    }
    for (auto i = data.begin(); i != data.end(); i++)
    {
        if((**i).getCarPrice()>1000000 && (**i).getEngine()->getEngineType()==EngineType::ICT){
            total+=(**i).getEngine()->getEngineHorsePower();
            count++;
        }
    }
    return total/count;
}

// Find CarId of the Car with Lowest car Price
void CarIdwithLowestCarPrice(Container &data)
{
    float min=0.0f;
    std::string id;
    if(Check(data)){
        std::runtime_error("Empty Container");
    }
    for (auto i = data.begin(); i != data.end(); i++)
    {
        if((**i).getCarPrice()<min){
            min=(**i).getCarPrice();
            id=(**i).getCarId();
        }
    }
    std::cout<<"Car ID with lowest car Price: "<<id;
}

//Add Two CarPrice
float CarPrice(Car &ob1, Car &ob2)
{
    return ob1+ob2;
}


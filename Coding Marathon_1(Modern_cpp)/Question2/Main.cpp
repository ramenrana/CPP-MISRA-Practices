#include <iostream>
#include "Engine.h"
#include "EngineType.h"
#include "Car.h"
#include "CarType.h"
#include "Functionalities.h"
#include <memory>
#include <list>
#include<thread>


using Contain=std::list<std::unique_ptr<Car>>;

int main(){
    Contain car;
    //CreateObject(car);
    std::thread t1(&CreateObject,std::ref(car));
    t1.join();
    std::cout<<EngineHorsePowerWithCarId(car,"101");
    std::optional<std::list<Car*> > torque=EngineTorque(car);

    if(torque.has_value()){
        for(auto &val:torque.value()){
            std::cout<<val;
        }
    }
}
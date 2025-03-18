#include "Engine.h"
#include "EngineType.h"

//overload << operator for display object
std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
    os << "engineNumber: " << rhs.engineNumber
       << " engineType: " << DisplayType(rhs.engineType)
       << " engineHorsePower: " << rhs.engineHorsePower
       << " engineTorque: " << rhs.engineTorque;
    return os;
}
//Display Engine type
std::string DisplayType(EngineType type)
{
    if(EngineType::HYBRID==type){
        return "HYBRID";
    }else{
        return "ICT";
    }
}
//@brief parameterized constructor
Engine::Engine(std::string engineNumber, EngineType engineType, int engineHorsePower, int engineTorque)
    : engineNumber(engineNumber), engineType(engineType), engineHorsePower(engineHorsePower), engineTorque(engineTorque)
{
}

//@brief Destructor
Engine::~Engine()
{
    std::cout<<"Engine Number "
            <<this->engineNumber
            <<"Deleted";
}

#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include "EngineType.h"

class Engine
{
private:
    std::string engineNumber;
    EngineType engineType;
    int engineHorsePower;
    int engineTorque;
public:
    
    ///@brief Default Constructor 
    Engine()=default;
    
    ///@brief Default copy constructor 
    Engine(Engine &obj)=default;
    
    ///@brief Move Constructor Deleted
    Engine(Engine &&obj)=delete;
    
    ///@brief parameterized constructor 
    Engine(std::string engineNumber,EngineType engineType,int engineHorsePower,int engineTorque);
    
    ///@brief Destructor
    ~Engine();

    ///Getter Setter Functions 
    std::string getEngineNumber() const { return engineNumber; }
    void setEngineNumber(const std::string &engineNumber_) { engineNumber = engineNumber_; }

    EngineType getEngineType() const { return engineType; }
    void setEngineType(const EngineType &engineType_) { engineType = engineType_; }

    int getEngineHorsePower() const { return engineHorsePower; }
    void setEngineHorsePower(int engineHorsePower_) { engineHorsePower = engineHorsePower_; }

    int getEngineTorque() const { return engineTorque; }
    void setEngineTorque(int engineTorque_) { engineTorque = engineTorque_; }
    
    //overload << operator for display object
    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);
};
//Display Engine type
std::string DisplayType(EngineType type);

#endif // ENGINE_H

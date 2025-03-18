#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "CarType.h"
#include "Engine.h"
#include "EngineType.h"
#include <memory>

using carEngine=std::unique_ptr<Engine>;

class Car
{
private:
    std::string carId;
    std::string carBrand;
    carType CARTYPE;
    carEngine engine; 
    float carPrice;
public:
    //@ brief Default Constructor 
    Car()=default;
    
    //@ brief Default copy constructor 
    Car(const Car &obj)=default;
    
    //@brief Move Constructor Deleted
    Car(Car &&obj)=delete;
    
    //@brief parameterized constructor 
    Car(std::string carId,
        std::string carBrand,
        carType CARTYPE,
        carEngine&& eng, 
        float carPrice
    );
    
    //@brief Destructor
    ~Car();

    //@brief overlod = operator for copy RHS to LHS;
    void operator =( Car &obj);

    //@brief overload + operator for add 2 customerStore Credit
    float operator +(Car &obj);

    std::string getCarId() const { return carId; }
    void setCarId(const std::string &carId_) { carId = carId_; }

    std::string getCarBrand() const { return carBrand; }
    void setCarBrand(const std::string &carBrand_) { carBrand = carBrand_; }

    carType cARTYPE() const { return CARTYPE; }
    void setCARTYPE(const carType &cARTYPE) { CARTYPE = cARTYPE; }

    carEngine& getEngine() { return engine; }
    void setEngine(carEngine &engine_) { engine = std::move(engine_); }

    float getCarPrice() const { return carPrice; }
    void setCarPrice(float carPrice_) { carPrice = carPrice_; }

    //overload << operator for display object
    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
    
};
//@brief Display the CarType
std::string DisplayCarType(carType type);

#endif // CAR_H

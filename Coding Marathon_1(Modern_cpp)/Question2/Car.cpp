#include "Car.h"
#include "CarType.h"

//overload << operator for display object
std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "carId: " << rhs.carId
       << " carBrand: " << rhs.carBrand
       << " CARTYPE: " << DisplayCarType(rhs.CARTYPE)
       << " engine: " << *(rhs.engine)
       << " carPrice: " << rhs.carPrice;
    return os;
}

//@brief Display the CarType
std::string DisplayCarType(carType type)
{
    if(carType::HATCHBACK==type){
        return "HATCHBACK";
    }else if(carType::SEDAN==type){
        return "SEDAN";
    }else if(carType::SPORTS==type){
        return "SPORTS";
    }else{
        return "SUV";
    }

}

//@brief parameterized constructor 
Car::Car(std::string carId, std::string carBrand, carType CARTYPE, carEngine&& eng, float carPrice)
:carId(carId),carBrand(carBrand),CARTYPE(CARTYPE),engine(std::move(eng)),carPrice(carPrice){
}

//@brief Destructor
Car::~Car()
{
    std::cout<<"Car with ID"
            <<this->carId
            <<"Deleted";
}

//@brief overlod = operator for copy RHS to LHS;
void Car::operator=( Car &obj)
{
    this->carId=obj.carId;
    this->carBrand=obj.carBrand;
    this->CARTYPE=obj.CARTYPE;
    this->engine=std::move(obj.engine);
    this->carPrice=obj.carPrice;
}
//@brief overload + operator for add 2 customerStore Credit
float Car::operator+(Car &obj)
{
    float price = 0;
    price = this->carPrice + obj.carPrice;
    return price;
}

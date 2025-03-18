#include "Driver.h"
std::ostream &operator<<(std::ostream &os, const Driver &rhs) {
    os << "drverName: " << rhs.driverName
       << " driverCatagory: " <<EnumType( rhs.driverCatagory)
       << " driverBirthYear: " << rhs.driverBirthYear
       << " driverLicence: " << *rhs.driverLicence.get();
    return os;
}

//Display the Enum type by passing an enum value
std::string EnumType(DriverCatagory type)
{
    if(DriverCatagory::COMMERCIAL==type){
        return "COMMERCIAL";
    }else{
        return "PRIVATE";
    }
}

//@Parameterized Constructor by passing  __  argument
Driver::Driver(std::string driverName, DriverCatagory driverCatagory, int driverBirthYear, Reference driverLicence)
:driverName(driverName),driverCatagory(driverCatagory),driverLicence(driverLicence){
    if(driverBirthYear>1947 && driverBirthYear<2023){
        this->driverBirthYear=driverBirthYear;
    }
}

Driver::~Driver()
{
    std::cout<<"Driver Deleted\n";
}

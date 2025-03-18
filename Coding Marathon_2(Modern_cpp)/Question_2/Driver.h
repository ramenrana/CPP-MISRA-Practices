#ifndef DRIVER_H
#define DRIVER_H

#include <iostream> 
#include "DriverCatagory.h"
#include <memory>
#include <functional>
#include "License.h"

using Reference =std::reference_wrapper<std::shared_ptr<License>>;

class Driver
{
private:
    std::string driverName;
    DriverCatagory driverCatagory;
    int driverBirthYear;
    Reference driverLicence;
public:

    //@Default Constructor is disabled
    Driver()=delete;
    
    //@Copy Constructor is disabled/enabled
    Driver(Driver &obj)=default;
    
    //@Move Constructor is disabled/enabled
    Driver(Driver &&obj)=delete;
    
    //@Parameterized Constructor by passing  __  argument
    Driver(
         std::string drverName,
        DriverCatagory driverCatagory,
        int driverBirthYear,
        Reference driverLicence
    );

    //@Destructor : for destroying the ___ object 
    ~Driver();

    //@Getter & Setter functions
    std::string getDrverName() const { return driverName; }
    void setDrverName(const std::string &drverName_) { driverName = drverName_; }

    DriverCatagory getDriverCatagory() const { return driverCatagory; }
    void setDriverCatagory(const DriverCatagory &driverCatagory_) { driverCatagory = driverCatagory_; }

    int getDriverBirthYear() const { return driverBirthYear; }
    void setDriverBirthYear(int driverBirthYear_) { driverBirthYear = driverBirthYear_; }

    Reference getDriverLicence() const { return driverLicence; }
    void setDriverLicence(const Reference &driverLicence_) { driverLicence = driverLicence_; }
    
    //overload ostream << operator for displaying the data member of this class
    friend std::ostream &operator<<(std::ostream &os, const Driver &rhs);
       
};

//Display the Enum type by passing an enum value
std::string EnumType(DriverCatagory type);

#endif // DRIVER_H

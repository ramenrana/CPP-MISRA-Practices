#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include "Driver.h"
#include "License.h"
#include <functional>
#include <memory>
#include <list>

using Pointer=std::shared_ptr<Driver>;
using Container =std::list<Pointer>;
using LicenseContainer=std::list<std::shared_ptr<License>>;



/*
    Check Wheather A list is Empty or not
*/
extern std::function<bool(Container &data)> CheckIsEmpty;

/*
    Create list of License Object
*/
extern std::function<void(LicenseContainer &data)> CreateLicense;

/*
    Create list of Driver Objects
*/
extern std::function<void(Container &data,LicenseContainer &ldata)> CreateDriver;

/*
    Return first N License whose driverBirthYear is 1960 or less 
*/
extern std::function<LicenseContainer(Container &data,int N)> ReturnLicencWhoseDriverDBYIsless1960;

/*
    Return first N Driver whose license catagory either COMMERCIL or PERSONAL
*/
extern std::function<Container (Container &data,int N)> ReturnDriverWhoseLicenceCatagoryMatch;

/*
    Return All driver whose License is licenseIssuingRTO  Matched
*/
extern std::function<Container (Container &data,std::string licenseIssuingRTO)> ReturnDriverWithlicenseIssuingRTOMatch;

/*
     Return All driver whose License is licenseIssuingStae Matched
*/
extern std::function<Container (Container &data,std::string licenseIssuingState)> ReturnDriverWithlicenseIssuingRTOMatch;

/*
    Return All License Instances whose licenseValidity year >8 and lincense CAtagory COMMERCIAL
*/
extern std::function<LicenseContainer(LicenseContainer &data)> ReturnAllLicenseInstancesYearless8andcatagory_commercial;

/*
    Demonstrate All Functionalities
*/
extern std::function<void ()> Demonstrate;

#endif // FUNCTIONALITIES_H

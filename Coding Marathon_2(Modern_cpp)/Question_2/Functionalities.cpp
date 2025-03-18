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
 std::function<bool(Container &data)> CheckIsEmpty=[](Container &data){
    if(data.empty()){
        return true;
    }else{
        return false;
    }
 };

/*
    Create list of License Object
*/
 std::function<void(LicenseContainer &data)> CreateLicense=[](LicenseContainer &data){
    data.emplace_back(std::make_shared<License>("101L",9,LicenceCatagory::COMMERCIAL,"123R","WB"));
    data.emplace_back(std::make_shared<License>("102L",6,LicenceCatagory::SPECIAL_PURPOSE,"124R","MH"));
    data.emplace_back(std::make_shared<License>("103L",10,LicenceCatagory::COMMERCIAL,"125R","WB"));
 };

/*
    Create list of Driver Objects
*/
 std::function<void(Container &data,LicenseContainer &ldata)> CreateDriver=[](Container &data,LicenseContainer &ldata){
    auto itr=ldata.begin();

    data.emplace_back(std::make_shared<Driver>(
        "RAM",
        DriverCatagory::COMMERCIAL,
        1949,
        std::ref(*itr)
    ));
    ++itr;
    data.emplace_back(std::make_shared<Driver>(
        "SHYAM",
        DriverCatagory::COMMERCIAL,
        1967,
        std::ref(*itr)
    ));
    ++itr;
    data.emplace_back(std::make_shared<Driver>(
        "JADU",
        DriverCatagory::PRIVATE,
        2021,
        std::ref(*itr)
    ));
 };

/*
    Return first N License whose driverBirthYear is 1960 or less 
*/
 std::function<LicenseContainer(Container &data,int N)> ReturnLicencWhoseDriverDBYIsless1960=[](Container &data,int N){
    if(CheckIsEmpty(data)){
        throw std::runtime_error("List is Empty!!");
    }
    if(N>data.size()){
        throw std::runtime_error("Invalid Size!!");
    }
    LicenseContainer result;
    for(auto &val:data ){
        if(val->getDriverBirthYear()<=1960){
            result.emplace_back(val->getDriverLicence());
        }
    }
    return result;
 };

/*
    Return first N Driver whose license catagory either COMMERCIL or PERSONAL
*/
 std::function<Container (Container &data,int N)> ReturnDriverWhoseLicenceCatagoryMatch=[](Container &data,int N){
    if(CheckIsEmpty(data)){
        throw std::runtime_error("List is Empty!!");
    }
    if(N>data.size()){
        throw std::runtime_error("Invalid Size!!");
    }
    Container result;
    for(auto &val:data ){
        if(val->getDriverLicence().get()->getLicenceCatagory()==LicenceCatagory::COMMERCIAL ||
         val->getDriverLicence().get()->getLicenceCatagory()==LicenceCatagory::PERSONAL){
            result.emplace_back(val);
        }
    }
    return result;
 };

/*
    Return All driver whose License is licenseIssuingRTO  Matched
*/
 std::function<Container (Container &data,std::string licenseIssuingRTO)> ReturnDriverWithlicenseIssuingRTOMatch=[](Container &data,std::string licenseIssuingRTO){
    if(CheckIsEmpty(data)){
        throw std::runtime_error("List is Empty!!");
    }
  
    Container result;
    for(auto &val:data ){
        if(val->getDriverLicence().get()->getLicenceIssuingRTO()==licenseIssuingRTO){
            result.emplace_back(val);
        }
    }
    return result;
 };

/*
     Return All driver whose License is licenseIssuingStae Matched
*/
 std::function<Container (Container &data,std::string licenseIssuingState)> ReturnDriverWithlicenseIssuingRTOMatch=[](Container &data,std::string licenseIssuingState){
    if(CheckIsEmpty(data)){
        throw std::runtime_error("List is Empty!!");
    }
  
    Container result;
    for(auto &val:data ){
        if(val->getDriverLicence().get()->getLicenseIssuingState()==licenseIssuingState){
            result.emplace_back(val);
        }
    }
    return result;
 };

/*
    Return All License Instances whose licenseValidity year >8 and lincense CAtagory COMMERCIAL
*/
 std::function<LicenseContainer(LicenseContainer &data)> ReturnAllLicenseInstancesYearless8andcatagory_commercial=[](LicenseContainer &data){
  
    LicenseContainer result;
    for(auto &val:data ){
        if(val->getLicenseValidityYears()>8 && val->getLicenceCatagory()==LicenceCatagory::COMMERCIAL){
            result.emplace_back(val);
        }
    }
    return result;
 };

/*
    Demonstrate All Functionalities
*/
 std::function<void ()> Demonstrate=[](){
    LicenseContainer ldata;
    Container data;
    CreateLicense(ldata);
    CreateDriver(data,ldata);

    // for(auto &val: ReturnLicencWhoseDriverDBYIsless1960(data,3)){
    //     std::cout<<*val;
    // }

    //  for(auto &val: ReturnDriverWhoseLicenceCatagoryMatch(data,3)){
    //     std::cout<<*val;
    // }

    //  for(auto &val: ReturnDriverWithlicenseIssuingRTOMatch(data,"123R")){
    //     std::cout<<*val;
    // }

 };

#endif // FUNCTIONALITIES_H

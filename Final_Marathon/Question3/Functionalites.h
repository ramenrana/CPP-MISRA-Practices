#ifndef FUNCTIONALITES_H
#define FUNCTIONALITES_H

 #include <iostream>
 #include <memory>
 #include <map>
 #include "SalariedTaxPlayer.h"
 #include <future>


using Pointer = std::unique_ptr<SalariedTaxPlayer>;
using Container = std::map<std::string,Pointer> ;

//Create list of object in Key Value Pair
void CreateObject(Container &data);

/// @brief Display Tax  
/// @param data 
/*
    if income <1000000 tax 100000
    income >100000 && <2000000 tax 150000
    else tax 200000
*/
void DisplayTax(Container &data);

/// @brief Display true or false if all monthly Salary < 50000 
/// @param data 
void DisplayMonthLySalaryless50000(Container &data);

/// @brief Display Count of all instances whose income value over 20,00000
void DisplayCountAllInstancesWhoseIncomeOver2000000(Container &data);

/// @brief Display first N instances whereN is passed by future input
void DisplayNInstances(Container &data,std::future<int>& ft);

void Demonstrate();
#endif // FUNCTIONALITES_H

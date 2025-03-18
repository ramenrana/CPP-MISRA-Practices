#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include "Customer.h"
#include "CustomerType.h"
#include <memory>
#include <list>


using pointer= std::shared_ptr<Customer>;
using Container=std::list<pointer>;

//@ brief create objects of type Customer

void createObjects(Container &data);

//@brief find Customer with Customer ID and Display the highest customerTransactionAmount

void FindCustomerIdHighesttransaction(Container &data);

//@brief return a container of Customer Objects whose customer type match

std::list<pointer> MatchCustomerType(Container &data, CustomerType type);

//@brief Return a container whose customerStoresCredits are between 100 and 200

std::list<pointer> CustomerStoreCreditBetween(Container &data);

//@brief Display the sum of lowest and highest customer store Credit

void SumHighLowCustomerCredfit(Container &data);

//@brief return average customer Store Credit whose customer type is matched

float AverageCustomerStoreCreditWithMatchingType(Container &data, CustomerType type);

//@brief print all customer instance whose type is matching

void DisplayCustomerWithMatchingType(Container &data,CustomerType type);

//Return true If the Container is empty()

bool CheckContainer(Container &data);

#endif // FUNCTIONALITIES_H

#include <iostream>
#include "Customer.h"
#include "CustomerType.h"
#include "Functionalities.h"
#include <memory>
#include <list>

//using Contain=std::list<std::unique_ptr<Customer>>;

int main(){
    Container d;
    createObjects(d);
    for(auto &val:MatchCustomerType(d,CustomerType::REGULAR)){
        std::cout<<*val;
    }
    
    //SumHighLowCustomerCredfit(d);
}
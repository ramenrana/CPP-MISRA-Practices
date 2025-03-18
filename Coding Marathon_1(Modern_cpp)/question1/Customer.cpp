#include "Customer.h"
#include "CustomerType.h"
std::ostream &operator<<(std::ostream &os, Customer &rhs) {
    os << "customerId: " << rhs.customerId
       << " customerName: " << rhs.customerName
       << " customerType: " << DisplayCustomerType(rhs.customerType);
       for(auto i:rhs.customerTransactionAmounts){
        os<< " customerTransactionAmounts: " << i; 
       }
       
       os<< " customerStoreCredit: " << rhs.customerStoreCredit;
    return os;
}
//@ display  Type pf Customer
std::string DisplayCustomerType(CustomerType type)
{
    if(CustomerType::PREMIMUM==type){
        return "PREMIMUM";
    }else if(CustomerType::REGULAR==type){
        return "REGULAR";
    }else{
        return "VIP";
    }
}

//@brief explicit one arg constructor 
Customer::Customer(int customerId):customerId(customerId)
{
}
//@brief parameterized constructor 
Customer::Customer(int customerId, std::string customerName, CustomerType customerType, std::list<int> customerTransactionAmounts, float customerStoreCredit)
:customerId(customerId),customerName(customerName),customerType(customerType),
customerTransactionAmounts(customerTransactionAmounts),
customerStoreCredit(customerStoreCredit){
}

//@brief Destructor
Customer::~Customer()
{
    std::cout<<"Customer ID"
            <<this->customerId
            <<"Deleted";
}

//@brief overlod = operator for copy RHS to LHS;
void Customer::operator=(const Customer &obj)
{
    this->customerId=obj.customerId;
    this->customerName=obj.customerName;
    this->customerType=obj.customerType;
    this->customerStoreCredit=obj.customerStoreCredit;
    this->customerTransactionAmounts=obj.customerTransactionAmounts;
}

//@brief overload + operator for add 2 customerStore Credit
void Customer::operator+(const Customer &obj)
{
    this->customerStoreCredit=this->customerStoreCredit+obj.customerStoreCredit;
}

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "CustomerType.h"
#include <iostream>
#include <list>

using Amount=std::list<int>;
class Customer
{
private:
    int customerId;
    std::string customerName;
    CustomerType customerType;
    Amount customerTransactionAmounts;
    float customerStoreCredit;
public:
    ///@brief Default Constructor 
    Customer()=default;
    
    ///@brief Default copy constructor 
    Customer(Customer &obj)=default;
    
    ///@brief Move Constructor Deleted
    Customer(Customer && obj)=delete;
    
    ///@brief explicit one arg constructor 
    explicit Customer(int customerId);

    ///@brief parameterized constructor 
    Customer(int customerId,
        std::string customerName,
        CustomerType customerType,
        std::list<int> customerTransactionAmounts,
        float customerStoreCredit
        );
    //@brief Destructor    
    ~Customer();
    
    //@brief getter Setter functions 
    int getCustomerId() const { return customerId; }
    void setCustomerId(int customerId_) { customerId = customerId_; }

    std::string getCustomerName() const { return customerName; }
    void setCustomerName(const std::string &customerName_) { customerName = customerName_; }

    CustomerType getCustomerType() const { return customerType; }
    void setCustomerType(const CustomerType &customerType_) { customerType = customerType_; }

    std::list<int> getCustomerTransactionAmounts() const { return customerTransactionAmounts; }
    void setCustomerTransactionAmounts(const std::list<int> &customerTransactionAmounts_) { customerTransactionAmounts = customerTransactionAmounts_; }

    float getCustomerStoreCredit() const { return customerStoreCredit; }
    void setCustomerStoreCredit(float customerStoreCredit_) { customerStoreCredit = customerStoreCredit_; }

    //@brief overlod = operator for copy RHS to LHS;
    void operator =(const Customer &obj);

    //@brief overload + operator for add 2 customerStore Credit
    void operator +(const Customer &obj);
    
    //@ overload << operator for display data values
    friend std::ostream &operator<<(std::ostream &os, Customer &rhs);
};
std::string DisplayCustomerType(CustomerType type);

#endif // CUSTOMER_H

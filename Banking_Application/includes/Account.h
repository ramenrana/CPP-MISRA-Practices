#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>

class Account
{
private:
    double balance;
public:
    Account(/* args */) = default;
    Account(double bal);
    ~Account() = default;
    virtual void credit(double bal);
    virtual bool debit(double bal);

    double getBalance(void) const { return balance; }
    void setBalance(double balance_) { 
        if (balance_ > 0.0){
            balance = balance_;
         } else {
            balance = 0.0;
            std::cerr<<"Amount should be greter than zero!!!!"<<std::endl;
         } 
    }
};


#endif // ACCOUNT_H

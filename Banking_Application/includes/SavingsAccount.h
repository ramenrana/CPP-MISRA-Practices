#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"
#include <iostream>

class SavingsAccount : public Account
{
private:
    double rate_of_interest;
public:
    SavingsAccount(/* args */) =default;
    SavingsAccount(double bal, double roi);
    ~SavingsAccount() = default;

    double calculateInterest() const;
    void credit(double bal) override;
    bool debit(double bal) override;

    double rateOfInterest(void) const { return rate_of_interest; }
    void setRateOfInterest(double rateOfInterest) { rate_of_interest = rateOfInterest; }

};


#endif // SAVINGSACCOUNT_H

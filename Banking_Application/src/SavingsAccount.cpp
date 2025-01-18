#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(double bal, double roi) : Account(bal)
{
    this->rate_of_interest = roi;
}

double SavingsAccount::calculateInterest(void) const
{
    return getBalance() * rateOfInterest();
}

void SavingsAccount::credit(double bal)
{
    Account::credit(calculateInterest()+bal);
}

bool SavingsAccount::debit(double bal)
{
    bool success = Account::debit(bal);
    return success;
}

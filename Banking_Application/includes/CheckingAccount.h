#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"
#include <iostream>

class CheckingAccount : public Account
{
private:
    double Transactionfee;
public:
    CheckingAccount(/* args */) = default;
    CheckingAccount(double bal, double fee);
    ~CheckingAccount() = default;

    void credit(double bal) override;
    bool debit(double bal) override;

    double transactionfee(void) const { return Transactionfee; }
    void setTransactionfee(double transactionfee) { Transactionfee = transactionfee; }
};

#endif // CHECKINGACCOUNT_H

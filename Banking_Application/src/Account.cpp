#include "Account.h"

Account::Account(double bal)
{
    setBalance(bal);
}

void Account::credit(double bal)
{
    if (bal > 0.0) {
        balance += bal;
    }else{
        balance += 0.0;
        std::cerr<<"Please Enter the amount of greater than zero!!"<<std::endl;
    }
}

bool Account::debit(double bal)
{
    bool success = false;
    if (bal <= balance) {
        balance -= bal;
        success = true;
    }else{
        std::cerr<<"Debit amount exceeded account balance!!!!"<<std::endl;
    }
    return success;
}

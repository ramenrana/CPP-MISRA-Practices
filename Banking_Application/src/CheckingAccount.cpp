#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(double bal, double fee) : Account(bal)
{
    this->Transactionfee = fee; 
}

void CheckingAccount::credit(double bal)
{
    Account::credit(bal - transactionfee());
}

bool CheckingAccount::debit(double bal)
{
    bool success = Account::debit(bal);
        if (success) {
            success = Account::debit(transactionfee()); /* Charge fee for successful withdrawal */
        }
        return success;
}

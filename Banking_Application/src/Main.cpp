#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <iostream>

int main(void) {
    double Saving_balance = 1000.00;
    double Saving_interest = 7.5;
    SavingsAccount savings(Saving_balance, Saving_interest); /* Initial balance 1000.00, interest rate 7.5% */

    double Initialbalance = 500.00;
    double TransactionFee = 2.0;
    CheckingAccount checking(Initialbalance, TransactionFee); /* Initial balance 500.00, transaction fee 2.0% */

    savings.credit(savings.calculateInterest());
    bool success = checking.debit(100);
    if (success) {
        std::cout<< "Transaction Successfull!!"<<std::endl;
    } else {
        std::cerr<<"Transaction Unsuccessfull!!"<<std::endl;
    }
    std::cout << "Savings Account Balance: " << savings.getBalance() << std::endl;
    std::cout << "Checking Account Balance: " << checking.getBalance() << std::endl;
}
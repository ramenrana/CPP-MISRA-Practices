#include "SalariedTaxPlayer.h"
std::ostream &operator<<(std::ostream &os, const SalariedTaxPlayer &rhs) {
    os << "_name: " << rhs._name
       << " _cardNumber: " << rhs._cardNumber
       << " _income: " << rhs._income
       << " _monthlySalary: " << rhs._monthlySalary;
    return os;
}
SalariedTaxPlayer::SalariedTaxPlayer(std::string _name, std::string _cardNumber, float _income, float _monthlySalary)
:_name(_name),_cardNumber(_cardNumber),_income(_income),_monthlySalary(_monthlySalary){
}

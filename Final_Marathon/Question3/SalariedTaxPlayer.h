#ifndef SALARIEDTAXPLAYER_H
#define SALARIEDTAXPLAYER_H

#include <iostream>

class SalariedTaxPlayer
{
private:
    std::string _name;
    std::string _cardNumber ;
    float _income;
    float _monthlySalary;
public:
    /// @brief Default Constructor Disable
    SalariedTaxPlayer(/* args */)=delete;
    /// @brief Copy Constructor Enables
    /// @param obj 
    SalariedTaxPlayer(SalariedTaxPlayer &obj)=default;

    /// @brief Move Constructor Disable
    /// @param obj 
    SalariedTaxPlayer(SalariedTaxPlayer &&obj)=delete;

    /// @brief Parameterized Constructor
    /// @param _name 
    /// @param _cardNumber 
    /// @param _income 
    /// @param _monthlySalary 
    SalariedTaxPlayer(
        std::string _name,
        std::string _cardNumber,
        float _income,
        float _monthlySalary
    );

    /// @brief Destructor Enabled
    ~SalariedTaxPlayer()=default;

    /// @brief Getter Setter Function

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    std::string cardNumber() const { return _cardNumber; }
    void setCardNumber(const std::string &cardNumber) { _cardNumber = cardNumber; }

    float income() const { return _income; }
    void setIncome(float income) { _income = income; }

    float monthlySalary() const { return _monthlySalary; }
    void setMonthlySalary(float monthlySalary) { _monthlySalary = monthlySalary; }

    /// @brief Overload << operator
    /// @param os 
    /// @param rhs 
    /// @return 
    friend std::ostream &operator<<(std::ostream &os, const SalariedTaxPlayer &rhs);
    
};

#endif // SALARIEDTAXPLAYER_H

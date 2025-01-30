#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <map>

/* @brief  The internal representation of a Polynomial is an array of terms.*/
class Polynomial
{
private:
    /* @brief  map of exponent as key and coefficient as value and representing in descending order as per key*/
    std::map<int,double, std::greater<int>> terms;
public:
    /* @brief  Default Constructor */
    Polynomial() = default;
    /* @brief  Copy Constructor set as default */
    Polynomial(const Polynomial& obj) = default;
    /* @brief  Destructor set as default */
    ~Polynomial() = default;
    
    /* @brief A function representing to set the term as per coefficient value and exponent value */
    void SetTerm(double coeff, int exponent);
    
    /* @brief  Print the Data by standard output*/
    void print() const;
    /* @brief  Overload the addition operator ( + ) to add two Polynomials */
    Polynomial operator+(const Polynomial& obj) const;
    /* @brief  Overload the subtraction operator ( - ) to subtract two Polynomials */
    Polynomial operator-(const Polynomial& obj) const;
    /* @brief  Overload the multiplication operator ( * ) to multiply two Polynomials */
    Polynomial operator*(const Polynomial& obj) const;

    /* @brief Overload the addition assignment operator ( += ) */
    Polynomial& operator+=(const Polynomial& obj);
    /* @brief subtraction assignment operator ( -= ) */
    Polynomial& operator-=(const Polynomial& obj);
    /* @brief multiplication assignment operator ( *= ) */
    Polynomial& operator*=(const Polynomial& obj);

};

#endif // POLYNOMIAL_H

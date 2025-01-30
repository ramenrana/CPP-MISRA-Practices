#include "Polynomial.h"

/* @brief A function representing to set the term as per coefficient value and exponent value
 * @param coeff: Take a value of coefficient
 * @param exponent: Take a value of exponent
*/
void Polynomial::SetTerm(double coeff, int exponent)
{
    if (coeff != 0.0) {
        terms[exponent] += coeff;
        if (terms[exponent] == 0) {
            terms.erase(exponent);
        }
    } else {
        terms.erase(exponent);
    }
}

/* @brief  Print the Data by standard output*/
void Polynomial::print() const
{
    for (const auto& term : terms) {
        std::cout << term.second <<"x^"<< term.first<< " ";
    }
    std::cout << std::endl;
}

/* @brief  Overload the addition operator ( + ) to add two Polynomials 
 * @param  obj : Take an constant polynomial object by a reference
*/
Polynomial Polynomial::operator+(const Polynomial &obj) const
{
    Polynomial result = *this;
    for (const auto& term : obj.terms) {
        result.SetTerm(term.second, term.first);
    }
    return result;
}

/* @brief  Overload the subtraction operator ( - ) to subtract two Polynomials 
 * @param  obj : Take an constant polynomial object by a reference
*/
Polynomial Polynomial::operator-(const Polynomial &obj) const
{
    Polynomial result = *this;
    for (const auto& term : obj.terms) {
        result.SetTerm(-term.second, term.first);
    }
    return result;
}

/* @brief  Overload the multiplication operator ( * ) to multiply two Polynomials 
 * @param  obj : Take an constant polynomial object by a reference
*/
Polynomial Polynomial::operator*(const Polynomial &obj) const
{
    Polynomial result = *this;
    for (const auto& term1 : terms) {
        for (const auto& term2 : obj.terms) {
            result.SetTerm(term1.second * term2.second, term1.first + term2.first);
        }
    }
    return result;
}

/* @brief Overload the addition assignment operator ( += ) 
 * @param  obj : Take an constant polynomial object by a reference
*/
Polynomial &Polynomial::operator+=(const Polynomial &obj)
{
    *this = *this + obj;
    return *this;
}

/* @brief subtraction assignment operator ( -= ) 
 * @param  obj : Take an constant polynomial object by a reference
*/
Polynomial &Polynomial::operator-=(const Polynomial &obj)
{
    *this = *this - obj;
    return *this;
}

/* @brief multiplication assignment operator ( *= ) 
 * @param  obj : Take an constant polynomial object by a reference
*/
Polynomial &Polynomial::operator*=(const Polynomial &obj)
{
    *this = *this * obj;
    return *this;
}

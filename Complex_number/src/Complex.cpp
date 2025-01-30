#include "Complex.h"

/**
 * @brief Stream insertion operator for Complex object
 * 
 * @param os Output stream
 * @param rhs Complex object
 * @return std::ostream& Output stream for cascading calls
 */
std::ostream &operator<<(std::ostream &os, const Complex &rhs) {
    if (rhs.imaginary < 0){
        os << rhs.real << " - " << -rhs.imaginary << "i";
    } else {
        os << rhs.real << " + " << rhs.imaginary << "i";
    }
    return os;
}

/**
 * @brief Stream extraction operator for Complex object
 * 
 * @param in Input stream
 * @param rhs Complex object
 * @return std::istream& Input stream for cascading calls
 */
std::istream &operator>>(std::istream &in, Complex &rhs)
{
    char plusMinus, i;
    in >> rhs.real >> plusMinus >> rhs.imaginary >> i;

    if (in.fail() || (plusMinus != '+' && plusMinus != '-') || i != 'i') {
        in.setstate(std::ios::failbit);
        return in;
    }

    if (plusMinus == '-') {
        rhs.imaginary = -rhs.imaginary;
    }

    return in;
}

/**
 * @brief Construct a new Complex:: Complex object
 * 
 * @param real real part of the complex number
 * @param img imaginary part of the complex number
 */
Complex::Complex(int real, int img)
{
    this->real = real;
    this->imaginary = img;
}

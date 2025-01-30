#ifndef COMPLEX_H
#define COMPLEX_H
#include <sstream>

class Complex
{
private:
    int real;
    int imaginary;
public:
    /**
     * @brief Construct a new Complex object
     * @param real for real part
     * @param img for imaginary pary
    */
    Complex(int real = 0, int img = 0);

    /**
     * @brief Destructure for deleting the Complex object
    */
    ~Complex() = default;

    /**
     * @brief Getter function for getting the real number
     * @return int
    */
    int getReal() const { return real; }

    /**
     * @brief Setter function for setting the real number
     * @param real_
    */
    void setReal(int real_) { real = real_; }

    /**
     * @brief Getter function for getting the imaginary number
     * @return int
    */
    int getImaginary() const { return imaginary; }

    /**
     * @brief Setter function for setting the imaginary number
     * @param imaginary_
    */
    void setImaginary(int imaginary_) { imaginary = imaginary_; }

    /* stream insertion and stream extraction operators */
    friend std::ostream &operator<<(std::ostream &os, const Complex &rhs);
    friend std::istream &operator>>(std::istream &in, Complex &rhs);
};


#endif // COMPLEX_H

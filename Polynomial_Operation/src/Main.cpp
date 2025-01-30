#include "Polynomial.h"
#include <iostream>

int main(void) {
    /* Creating a object p1 */
    Polynomial p1;
    /* Initialize the values of exponent and coefficient */
    int expo1_p1 = 3;
    double coeff1_p1 = 2.0;
    /* SetTerm by passing exponenet and coefficient */
    p1.SetTerm(coeff1_p1, expo1_p1);
    /* Initialize the values of exponent and coefficient */
    int expo2_p1 = 2;
    double coeff2_p1 = 1.0;
    /* SetTerm by passing exponenet and coefficient */
    p1.SetTerm(coeff2_p1, expo2_p1);
    
    /* Showing the output of polynomial object p1*/
    std::cout << "Polynomial p1 : ";
    p1.print();

    /* Creating a object p2 */
    Polynomial p2;
    /* Initialize the values of exponent and coefficient */
    int expo1_p2 = 2;
    double coeff1_p2 = 3.0;
    /* SetTerm by passing exponenet and coefficient */
    p2.SetTerm(coeff1_p2, expo1_p2);
    /* Initialize the values of exponent and coefficient */
    int expo2_p2 = 1;
    double coeff2_p2 = 1.0;
    /* SetTerm by passing exponenet and coefficient */
    p2.SetTerm(coeff2_p2, expo2_p2);

    /* Showing the output of polynomial object p1*/
    std::cout << "Polynomial p2 : ";
    p2.print();

    /* Addition of two polynomial eq. by overloading + operator */
    Polynomial p3 = p1 + p2;
    std::cout << "p1 + p2 : ";
    p3.print();

    /* Addition of two polynomial eq. by overloading * operator */
    Polynomial p4 = p1 * p2;
    std::cout << "p1 * p2 : ";
    p4.print();

    /* Addition of two polynomial eq. by overloading =+ operator */
    p1 += p1;
    std::cout << "p1 += p1 : ";
    p1.print();

}
/* 12. 17.26 (Catching All Exceptions) Write a program that
*  demonstrates several exception types being caught with the
*  catch(...) exception handler.
*/
#include<iostream>

int main(void) {
    try
    {
        throw 'a';
    }
    catch(...)
    {
        std::cerr << "Exception Caught!!!" << '\n';
    }

    try
    {
        throw 2;
    }
    catch(...)
    {
        std::cerr << "Exception Caught!!!" << '\n';
    }
    
}
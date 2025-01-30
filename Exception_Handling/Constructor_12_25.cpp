/* 17.28 (Constructors Throwing Exceptions) Write a program
* that shows a constructor passing information about constructor
* failure to an exception handler after a try block.
*/

#include <iostream>

/* Purpose of this class is to showing a example of thowing exception from constructor*/
class Exception_demo
{
private:
    /* data */
public:
    /*Decleard constructor Exception_demo explicitly*/
    explicit Exception_demo(int value) {
        /*Check if the value is ZERO then throwing an exception*/
        if (value == 0) {
            throw "ZERO not accepted!!!";
        }
    }
    /* Implemented Destructor */
    ~Exception_demo(void) {
        std::cout<<"Destructor Called!!!\n";
    }
};

int main(void) {
    /* Try-catch block for avoiding abnormal termination of the program*/
    try
    {
        Exception_demo d(0); /* Here, Exception raised going to corresponding catch block*/
    }
    catch(const char* e)
    {
        /* Display error details*/
        std::cerr << "Exception Caught!! " <<e<< '\n';
    }
    

}
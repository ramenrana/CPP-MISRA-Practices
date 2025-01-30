/* 17.27 (Order of Exception Handlers) Write a program
* illustrating that the order of exception handlers is important.
* The first matching handler is the one that executes. Attempt to
* compile and run your program two different ways to show that
* two different handlers execute with two different effects
*/

#include <iostream>
#include <stdexcept>

class Demo : public std::runtime_error {
public: 
    Demo(void) : std::runtime_error{ "42" } {}
};

int main(void) {
   try 
   {
       throw Demo{};
   }
   catch ( const std::exception& )
   { 
       std::cerr << "Base handler\n";
   }
   catch ( const Demo& )
   { 
       std::cerr << "User handler\n";
   }

   try
   { 
       throw Demo{};
   }
   catch ( const Demo& )
   { 
       std::cerr << "User handler\n";
   }
   catch ( const std::exception& )
   { 
       std::cerr << "Base handler\n";
   }

}

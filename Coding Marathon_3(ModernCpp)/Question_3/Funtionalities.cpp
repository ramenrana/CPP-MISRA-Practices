#include "Funtionalities.h"

 /*
    Create list of object
*/
void CreateObject(){
   
    //data1.emplace_back(std::make_shared<Passenger>("1001P","AAAA",34,PassengerType::REGULAR,8000.0f));
    //using li=std::list<std::shared_ptr<Passenger> ;
    
    data=std::list<std::shared_ptr<Passenger>>{std::make_shared<Passenger>("1001P","AAAA",34,PassengerType::REGULAR,8000.0f)};
   

}

/*
    Demonstrate all funtionalities
*/
void Demonstrate(){

    
}

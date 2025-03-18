#include <iostream>
#include "Train.h"
#include "TicketClass.h"
#include "TrainTicket.h"
#include <memory>
#include <list>
#include <optional>
#include <vector>


using Pointer = std::shared_ptr<Train>;
using Container = std::vector<Pointer>;

/*
    A function to create an object of train class
*/

void createObjects(Container& data);


/*
    A function to find whether each trai instance has at least 3 tickets booke
*/

void AtLeast3TicketsBooked(Container& data);

/*
    A function to find and return a conatiner of train instances whose departure time is within 3 hours of the 
    hour parameter passed by the user 
*/

std::optional<Container> DepartureTimeWithin3Hours(Container& data , int x);


/*
    A function to sort a copy of train isntances in a container according to their departure time
*/
void SortDescendingOrder(Container& data);


/*
    A function to find ticket Type of all instances stored inside train instances
    whose ticket Price is above threshold value passed as a parameter
*/

std::list<TicketType> TicketTypeContainer(Container& data, float threshold);


/*
    A function to find thr train starting station of train 
    instance whose number is passed as an argument 
*/

void FindTrainStartingStation(Container& data,std::string number);

/* Demonstrate Functionlities*/
void DemonStrate();
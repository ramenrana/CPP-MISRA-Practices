#ifndef FUNTIONALITIES_H
#define FUNTIONALITIES_H

#include<iostream>
#include "PassengerType.h"
#include "Passenger.h"
#include <mutex>
#include <thread>
#include <memory>
#include <list>
#include <any>

using Pointer = std::shared_ptr<Passenger>;
using Container = std::list<Pointer>;
std::any data;
/*
    Create list of object
*/
void CreateObject();

/*
    Demonstrate all funtionalities
*/
void Demonstrate();

#endif // FUNTIONALITIES_H

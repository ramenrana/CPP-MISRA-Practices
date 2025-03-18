#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include "Train.h"
#include "TrainTicket.h"
#include <memory>
#include <list>
#include <vector>
#include <optional>

using Pointer = std::shared_ptr<Train>;
using Container = std::vector<Pointer>;
using TicketTypeContainer =std::list<TicketType>;


void CreateObject(Container &data);

void CheckFor3TicketBook(Container &data);

std::optional<Container> ReturnContainerDepartureWithin3hrs(Container &data,int x);

void SortTrainInstances(Container &data);

std::optional<TicketTypeContainer>  ReturnTicketTypewhosePriceAboveTheshold(Container &data,float Price);

void DisplayTrainStartingStation(Container &data);

void Demonstrate();

#endif // FUNCTIONALITIES_H

#include <iostream>
#include "Functionalities.h"

int main()
{
    Container data;
    CreateObjects(data);
    AirplaneContainer one = AirplaneInstanceofTypeDomestic(data);
    for (auto &a : one)
    {
        std::cout << *a.get() << "\n";
    }
    AirPlaneType type = AirPlaneTypeHighestTicketPrice(data);
    AirplaneContainer two = AirPlaneInstanceAboveThreshold(data, 300);
    for (auto &a : two)
    {
        std::cout << *a.get() << "\n";
    }
    std::shared_ptr<Flight> result = FindByFlightTicketNumber(data, "1");
    std::cout << *result << "\n";
    AirPlaneType res2 = AirplaneTypeByTicketNumber(data, "2");
}
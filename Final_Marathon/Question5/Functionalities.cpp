#include "Functionalities.h"
#include <algorithm>
#include <numeric>


auto Tic1 = std::make_shared<TrainTicket>(10001.0f,TicketType::GENERAL,TicketClass::AC);
auto Tic2 = std::make_shared<TrainTicket>(100.0f,TicketType::WAITING,TicketClass::FIRST);
auto Tic3 = std::make_shared<TrainTicket>(13401.0f,TicketType::RESERVED,TicketClass::SECOND);
auto Tic4 = std::make_shared<TrainTicket>(101.0f,TicketType::GENERAL,TicketClass::SLEEPER);

void createObjects(Container &data)
{
    data.emplace_back(std::make_shared<Train>("T1","PUNE","MUMBAI",4,38,TicketContainer {Tic1,Tic2,Tic3}));
    data.emplace_back(std::make_shared<Train>("T2","Baramati","Pune",4,36,TicketContainer {Tic4,Tic1}));
    data.emplace_back(std::make_shared<Train>("T3","MUMBAI","DELHI",12,28,TicketContainer {Tic3,Tic2}));
    data.emplace_back(std::make_shared<Train>("T4","CHENNAI","PUNE",15,55,TicketContainer {Tic1,Tic4}));
}


void AtLeast3TicketsBooked(Container &data)
{
    bool res = std::all_of(
        data.begin(),
        data.end(),
        [](Pointer& ptr){return ptr->getTrainBookTickets().size() >= 3 ;}
    );
    std::cout << res;
}


std::optional<Container> DepartureTimeWithin3Hours(Container &data, int x)
{
    if(data.empty()){
        throw std::runtime_error("EMPTY");
    }
    Container result(data.size());

    auto itr = std::copy_if(
        data.begin(),
        data.end(),
        result.begin(),
        [&](Pointer& ptr){
            return ptr->getTrainDepartureHour() == x+1 || ptr->getTrainDepartureHour() == x+3 
                    || ptr->getTrainDepartureHour() == x+2;
        }
    );
    result.resize(std::distance(result.begin(),itr));
    return result;
}


void SortDescendingOrder(Container &data)
{
    std::sort(
        data.begin(),
        data.end(),
        [](Pointer& ptr,Pointer& ptr2) {return ptr->getTrainDepartureHour() < ptr2->getTrainDepartureHour();}
    );
   
    for(auto& a : data){
        std::cout << *a << "\n";
    }
}


std::list<TicketType> TicketTypeContainer(Container &data, float threshold)
{
    std::list<TicketType> result;
    for(auto & a : data){
        for(auto& b : a->getTrainBookTickets()){
            if(b->getTicketPrice() > threshold){
                result.emplace_back(b->getTicketType());
            }
        }
    }
    return result;

}

void FindTrainStartingStation(Container &data, std::string number)
{
    std::string result = "";
    for(auto& a : data)
    {
        float total = std::accumulate(
            a->getTrainBookTickets().begin(),
            a->getTrainBookTickets().end(),
            0.0f,
            [](float total ,auto& ptr){return total + ptr->getTicketPrice();}
        );
        if(a->getTrainNumber() == number && (a->getTrainDepartureHour() == 15 || a->getTrainDepartureHour()==16) 
            && total >= 2000){
                result = a->getTrainStartingStation();
            }
    }
    
    std::cout  << result <<"\n";
}

void DemonStrate()
{
    Container data;
    createObjects(data);
    AtLeast3TicketsBooked(data);
    std::optional<Container> result = DepartureTimeWithin3Hours(data,3);
    if(result.has_value()){
        for(auto& a : result.value()){
            std::cout << *a << "\n";
        }
    }
    SortDescendingOrder(data);
    std::list<TicketType> result2 = TicketTypeContainer(data,10002.0f);
   
}

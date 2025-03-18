#include "Functionalities.h"
#include <algorithm>
#include <numeric>



void CreateObject(Container &data)
{
    data.emplace_back(std::make_shared<Train>(
        "XX00",
        "XXX",
        "YYY", 
        15, 
        30, 
        std::list<std::shared_ptr<TrainTicket>>{
            std::make_shared<TrainTicket>(1000.00f, TicketType::RESERVED, TicketClass::FIRST),
            std::make_shared<TrainTicket>(2000.00f, TicketType::GENERAL, TicketClass::FIRST),
            std::make_shared<TrainTicket>(3000.00f, TicketType::WAITING, TicketClass::SECOND)
        }
       )
    );

    data.emplace_back(std::make_shared<Train>(
        "XX00",
        "XXX",
        "YYY", 
        15, 
        30, 
        std::list<std::shared_ptr<TrainTicket>>{
            std::make_shared<TrainTicket>(1000.00f, TicketType::RESERVED, TicketClass::FIRST),
            std::make_shared<TrainTicket>(3000.00f, TicketType::WAITING, TicketClass::SECOND)
        }
       )
    );
    
}

void CheckFor3TicketBook(Container &data)
{
    bool res = std::all_of(
        data.begin(),
        data.end(),
        [](Pointer &ptr)
        { return ptr->getTrainBookedTickets().size() >= 3; });
        
        std::cout<<res;
}


std::optional<Container> ReturnContainerDepartureWithin3hrs(Container &data, int x)
{
    Container res(data.size());

    auto itr=std::copy_if(
        data.begin(),
        data.end(),
        res.begin(),
        [&](Pointer &ptr){
            return
            x+1 < ptr->getTrainDepartureHour()
            ||
            x+2 < ptr->getTrainDepartureHour()
            ||
            x+3 < ptr->getTrainDepartureHour()
        ;}
    );

    res.resize(std::distance(res.begin(),itr));

    return res;
}

void SortTrainInstances(Container &data)
{
    std::sort(
        data.begin(),
        data.end(),
        [](Pointer &ptr, Pointer &ptr1)
        {
            return ptr->getTrainDepartureHour() < ptr1->getTrainDepartureHour();
        });

    for (auto &val : data)
    {
        std::cout << *val;
    }
}

std::optional<TicketTypeContainer> ReturnTicketTypewhosePriceAboveTheshold(Container &data, float Price)
{
    if (data.empty())
    {
        return {};
    }

    TicketTypeContainer result;
    for (auto &val : data)
    {
        for (auto &val1 : val->getTrainBookedTickets())
        {
            if (val1->getTicketPrice() > Price)
            {
                result.emplace_back(val1->getTicketType());
            }
        }
    }

    if (result.empty())
    {
        return {};
    }
    else
    {
        return result;
    }
}

void DisplayTrainStartingStation(Container &data, std::string number)
{

    float total = 0.0f;
    for (auto itr = data.begin(); itr != data.end(); itr++)
    {
        if ((**itr).getTrainNumber() == number &&
            ((**itr).getTrainDepartureHour() == 15 || (**itr).getTrainDepartureHour() == 16))
        {
            
            for (auto &val : (**itr).getTrainBookedTickets())
            {
                total += (*val).getTicketPrice();
            }
            if (total >= 2000.00f)
            {
                std::cout << (**itr).getTrainStartingStation();
            }
        }
    }
}

void Demonstrate()
{
    Container data;
    CreateObject(data);

    for(auto &val : data){
        std::cout<<*val;
    }

    CheckFor3TicketBook(data);

    std::optional<Container>res1= ReturnContainerDepartureWithin3hrs(data,5);
    
    if(res1.has_value()){
        
        for(auto &val: res1.value()){
           std::cout<<*val<<"\n";
         }

    }else{
        std::cout<<"Container EMPTY!!!";
    }

    SortTrainInstances(data);

    std::optional<TicketTypeContainer> res = ReturnTicketTypewhosePriceAboveTheshold(data,100.0f);
    if(res.has_value()){
        for(auto &val: res.value()){
           std::cout<<DisplayTicketType(val)<<"\n";
         }
    }else{
        std::cout<<"Container EMPTY!!!";
    }

   DisplayTrainStartingStation(data, "XX00");
}

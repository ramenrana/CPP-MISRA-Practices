#include "Functionalities.h"


//Return true If the Container is empty()
bool CheckContainer(Container &data)
{   if(data.empty() || data.size()==0){
    return true;
    }
    return false;
}
//@ brief create objects of type Customer
void createObjects(Container &data)
{
    data.emplace_back(std::make_shared<Customer>(101,"Ramen",CustomerType::PREMIMUM,Amount{100,239,300,567,635},5000));
    data.emplace_back(std::make_shared<Customer>(102,"Shyam",CustomerType::REGULAR,Amount{109,2376,376,5676,780},6000));
    data.emplace_back(std::make_shared<Customer>(103,"Ram",CustomerType::VIP,Amount{109,2329,3040,5367,6435},7000));
    data.emplace_back(std::make_shared<Customer>(104,"Souvo",CustomerType::REGULAR,Amount{1009,2309,3040,4567,4635},8000));
}

//@brief find Customer with Customer ID and Display the highest customerTransactionAmount
void FindCustomerIdHighesttransaction(Container &data)
{
    if(CheckContainer(data)){
        std::runtime_error("Conatiner is Empty!!");
    }
    auto itr = data.begin();
    int max=0;
    int id;
    for (auto i = data.begin(); i != data.end(); i++)
    {
        std::list<int> amt=(**i).getCustomerTransactionAmounts();
            for(auto i: amt){
                if(i>max){
                    max=i;
                    id=(**itr).getCustomerId();
                }
            }
    }
    std::cout<<"Custmer ID: "<<id;
}

//@brief return a container of Customer Objects whose customer type match

Container MatchCustomerType(Container &data, CustomerType type)
{

    Container data1;
    
    if(CheckContainer(data)){
        std::runtime_error("Conatiner is Empty!!");
    }
    for (auto i = data.begin(); i != data.end(); i++)
    {
        if((**i).getCustomerType()==type){
            data1.emplace_back(*i);
        }
    }
    return data1;
}

// //@brief Return a container whose customerStoresCredits are between 100 and 200
Container CustomerStoreCreditBetween(Container &data)
{
    Container data1;
    int max=0;
    if(CheckContainer(data)){
        std::runtime_error("Conatiner is Empty!!");
    }
    for (auto i = data.begin(); i != data.end(); i++)
    {
        if((**i).getCustomerStoreCredit()>100 && (**i).getCustomerStoreCredit()<200){
            data1.emplace_back(*i);
        }
    }
    return data1;
}

// //@brief Display the sum of lowest and highest customer store Credit
void SumHighLowCustomerCredfit(Container &data)
{
    int max=0;
    int min=0;
    if(CheckContainer(data)){
        std::runtime_error("Conatiner is Empty!!");
    }
    for (auto i = data.begin(); i != data.end(); i++)
    {
        if((**i).getCustomerStoreCredit()>max ){
            max=(**i).getCustomerStoreCredit();
        }
        if((**i).getCustomerStoreCredit()<min ){
            min=(**i).getCustomerStoreCredit();
        }

        std::cout<<"Sum of Highest and Lowest Customer Credit"<<max+min;
    }
}

// //@brief return average customer Store Credit whose customer type is matched
float AverageCustomerStoreCreditWithMatchingType(Container &data, CustomerType type)
{
    int count=0;
    int total =0;
    if(CheckContainer(data)){
        std::runtime_error("Conatiner is Empty!!");
    }
    for (auto i = data.begin(); i != data.end(); i++)
    {
        if((**i).getCustomerType()==type){
            total+=(**i).getCustomerStoreCredit();
        }
    }
    return total/count;
}

// //@brief print all customer instance whose type is matching
void DisplayCustomerWithMatchingType(Container &data, CustomerType type)
{
    if(CheckContainer(data)){
        std::runtime_error("Conatiner is Empty!!");
    }
    for (auto i = data.begin(); i != data.end(); i++)
    {
        if((**i).getCustomerType()==type){
            std::cout<<(**i);
        }
    }
}


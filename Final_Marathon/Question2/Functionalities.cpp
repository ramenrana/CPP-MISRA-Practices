#include "Functionalities.h"
#include <algorithm>
#include <numeric>

void CreateObject(Container &data)
{
    data.emplace_back(std::make_shared<Employee>(
        "E101",
        Department::DEVELOPMENT,
        std::make_shared<ActiveProject>("XXX",11,1000.00f,1000)
    ));
    data.emplace_back(std::make_shared<Employee>(
        "E102",
        Department::DEVELOPMENT,
        std::make_shared<ActiveProject>("XXX",11,2000.00f,100)
    ));
}

std::optional<Container> ReturnEmployee(Container &data)
{
    if(data.size()==0){
        return {};
    }
    Container result(data.size());
    auto itr=std::copy_if(
            data.begin(),
            data.end(),
            result.begin(),
            [](EmpPointer &ptr){
                return 
                (ptr.get()->department()==Department::DEVELOPMENT || ptr.get()->department()==Department::DEVELOPMENT)
                &&
                ptr.get()->activeProject().get()->projectTeamCount()>=10
                &&
                ptr.get()->activeProject().get()->projectCost()<10000.0f;
                }
    );
    result.resize(std::distance(result.begin(),itr));  

    if(result.size()){
        return {};
    }else{
        return result;
    }  
}

void LamdaFunctions(Container &data)
{
    int i=0;
    std::cout<<"Enter index: ";
    std::cin>>i;
    auto l1=[&](){
        if(i<data.size()){
            std::cout<<*(data[i]).get();
        }else{
            std::cout<<"Index Not Found";
        }
        };
    l1();
    auto l2 = [&](){
        if(data.size()==3){
            std::cout<<"True";
        }else{
            std::cout<<"False";
        }
        };
    l2();

    
}

float Average(Container &data)
{
    int count=0;
    float res =std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [&](float total,EmpPointer &ptr){
                if(ptr->department()==Department::DEVELOPMENT){
                    count++;
                    return total+ptr->activeProject().get()->projectCost();
                }
            }
    );
    return res/count;
}

std::optional<Container> ReturnEmployeeWhoseDurationabove225(Container &data)
{
    if(data.size()==0){
        return {};
    }

   Container result(data.size());
    auto itr=std::copy_if(
            data.begin(),
            data.end(),
            result.begin(),
            [](EmpPointer &ptr){
                return ptr.get()->activeProject().get()->projectDuration()>225;
                }
    );
    result.resize(std::distance(result.begin(),itr)); 

     if(data.size()==0){
        return {};
    }else{
        return result;
    }
    
}

void Demonstrate()
{
    Container data;
    CreateObject(data);
    for(auto &val: data){
        std::cout<<*val;
    }
    std::optional<Container> res2= ReturnEmployee(data);
    if(res2.has_value()){
        for(auto &val: res2.value()){
            std::cout<<*val;
        }
    }
   LamdaFunctions(data);
   std::cout<<Average(data);

    std::optional<Container> res1= ReturnEmployeeWhoseDurationabove225(data);
    if(res1.has_value()){
        for(auto &val: res1.value()){
            std::cout<<*val;
        }
    }
   

}

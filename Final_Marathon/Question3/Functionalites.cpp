#include "Functionalites.h"
#include <algorithm>


void CreateObject(Container &data){
    int n;
    std::string name;
    std::string cardNumer;
    float income;
    float salary;
    std::cin>>n;
    for(int i=0;i<n*4;i++){
        std::cin>>name;
        std::cin>>cardNumer;
        std::cin>>income;
        std::cin>>salary;
        data.emplace(cardNumer,std::make_unique<SalariedTaxPlayer>(name,cardNumer,income,salary));
    }

}

void DisplayTax(Container &data){
    for(auto &[k,v]:data){
        if(v.get()->income()<1000000.0f){
            std::cout<<"Tax : 1,00,000\n";
        }else if(v.get()->income()>1000000.0f && v.get()->income()<2000000.0f){
            std::cout<<"Tax : 1,50,000\n";
        }else {
            std::cout<<"Tax : 2,00,000\n";
        }
    }
}

void DisplayMonthLySalaryless50000(Container &data)
{
    
    bool a =std::all_of(
        data.begin(),
        data.end(),
        [](auto &ptr){return ptr.second->monthlySalary()<50000.0f;}
    );

    if(a==1){
        std::cout<<"YES";
    }else{
        std::cout<<"NO";
    }
}

void DisplayCountAllInstancesWhoseIncomeOver2000000(Container &data)
{
    std::cout<<std::count_if(
        data.begin(),
        data.end(),
        [](auto &ptr){return ptr.second->income()>2000000.0f;}
    );
}

void DisplayNInstances(Container &data, std::future<int>& ft)
{
    int N =ft.get();

        if(N>data.size()){
            std::runtime_error("N is Greater than !!!");
        }    
        for(auto &[k,v]:data){
            if(N>0){
                std::cout<<k<<*v.get();
            }
            N--;
        }
}

void Demonstrate(){
    Container data;
    CreateObject(data);

    for(auto &[k,v]:data){
        std::cout<<k<<*v.get();
    }

    DisplayTax(data);
    DisplayMonthLySalaryless50000(data);

   DisplayCountAllInstancesWhoseIncomeOver2000000(data);

    int number=0;
    std::promise<int> pr;
    std::future<int> ft = pr.get_future();

    auto res= std::async(std::launch::async,&DisplayNInstances,std::ref(data),std::ref(ft));
    std::cin>>number;
    pr.set_value(number);
}
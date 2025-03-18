#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Product.h"
#include "ProductOrigin.h"
#include "ProductType.h"
#include <iostream>
#include <functional>
#include <memory>
#include <list>
#include <set>

using Pointer=std::shared_ptr<Product>;
using Container=std::list<Pointer>;
using setContainer =std::set<std::string>;

/*
    Create an list of object of Product by lamda Function
*/
 std::function<void(Container &data)> CreateObject=[](Container &data){
    
    data.emplace_back(std::make_shared<Product>(
        "101",
        ProductType::APPLIANCE,
        56779.87f,
        "Samsung",
        ProductOrigin::DOMESTIC,
        600.00f
        ));

    data.emplace_back(std::make_shared<Product>(
        "102",
        ProductType::FMCG,
        98898.87f,
        "Apple",
        ProductOrigin::DOMESTIC,
        200.00f
        ));

    data.emplace_back(std::make_shared<Product>(
        "103",
        ProductType::FMCG,
        10008.87f,
        "Moto",
        ProductOrigin::DOMESTIC,
        100.00f
        ));

 };

/*
    Check Wheather the list is empty or not
*/
  std::function<bool(Container &data)> CheckIsEmpty=[](Container &data){
    if(data.empty()){
        return true;
    }else{
        return false;
    }
  };

/*
    Find and Return Average Product Price values for all products whose productType is provided as an argument

*/
  std::function<float(Container &data, ProductType type)> AverageProductPriceByType=[](Container &data, ProductType type){
    if(CheckIsEmpty(data)){
        throw std::runtime_error("List Is Empty");
    }
    float total=0.0f;
    int count =0;
    
    for(auto &val:data){
        if(val.get()->getProductType()==type){
            total+=val.get()->getProductPrice();
            count++;
        }
    }

    return total/count;
 };

/*
    Return productTaxAmount with the minimum productPrice 
*/
  std::function<float(Container &data)> ProductTaxAmountMinimumProductPrice=[](Container &data){
    float min=0.0f;
    float taxAmt;
    if(CheckIsEmpty(data)){
        throw std::runtime_error("List Is Empty");
    }
    for(auto &val:data){
        if(min<val.get()->getProductPrice()){
            min=val.get()->getProductPrice();
            taxAmt=val.get()->getProductTaxAmount();
        }
    }
    return taxAmt;
  };

/*
    Return a Container of First N instances of product where N is given as input
*/
  std::function<Container(Container &data,int N)> ReturnNInstancesOfProduct=[](Container &data,int N){
    Container FirstNInstances;
    if(CheckIsEmpty(data)){
        throw std::runtime_error("List Is Empty");
    }

    if(N==0){
            throw std::runtime_error("Number of Instances cant be O");
        }
        
    for(auto &val:data){
        if(N!=0){
            FirstNInstances.emplace_back(val);
            N--;
        }
    }
    return FirstNInstances;

  };

/*
    Identify and Return Unique productBrands
*/


  std::function<setContainer(Container &data)> UnqueProductBrand=[](Container &data){
    
    if(CheckIsEmpty(data)){
        throw std::runtime_error("List Is Empty");
    }
    
    setContainer brandname; 
    

    for(auto &val:data){

        brandname.insert(val.get()->getProductBrand());
        
    }

    return brandname;
  };
/*
    Return an Array Of 3 Integer where 3 positions indicate that

    count of FMCG productType
    count of DOMESTIC productOrigin
    count of Product Instances whose productPrice is >50
*/
  std::function<std::array<int,3>(Container &data)> CountOf3Features=[](Container &data){
    if(CheckIsEmpty(data)){
        throw std::runtime_error("List Is Empty");
    }
    std::array<int,3> arr;
    int cPType=0;
    int cPOrigin=0;
    int cPPrice=0;
    for(auto &val:data){
        if(val.get()->getProductType()==ProductType::FMCG){
            cPType++;
        }
        if(val.get()->getProductOrigin()==ProductOrigin::DOMESTIC ){
            cPOrigin++;
        }
        if(val.get()->getProductPrice()>50){
            cPPrice++;
        }
    }
    arr[0]=cPType;
    arr[1]=cPOrigin;
    arr[2]=cPPrice;

    return arr;
  };

/*
    Returns a container of Addresses for Product Instances whose ProductBrand Matches
*/

 std::function <Container (Container &data,std::string brand)> AddressOfProductInstancesMatchProductBrand=[](Container &data,std::string brand){
    Container result;
    if(CheckIsEmpty(data)){
        throw std::runtime_error("List Is Empty");
    }
    for(auto &val:data){
        if(val->getProductBrand() == brand){
            result.emplace_back(val);
        }
    }   
    return result;
 };

/*
    Demontrate The Functionalities
*/

std::function<void()> Demonstrate=[](){
    Container data;
    CreateObject(data);
    
    std::cout<<"Average :"<<ProductTaxAmountMinimumProductPrice(data)<<"\n";
    
    std::cout<<"Tax: "<<ProductTaxAmountMinimumProductPrice(data)<<"\n";
    
    for(auto &val:ReturnNInstancesOfProduct(data,2)){
        std::cout<<*val<<"\n";
    }

    for(auto &val:CountOf3Features(data)){
        std::cout<<val<<"\n";
    }

    for(auto &val:AddressOfProductInstancesMatchProductBrand(data,"Moto")){
        std::cout<<*val<<"\n";
    }

    setContainer brandName=UnqueProductBrand(data);
    auto itr=brandName.begin();

    for(itr;itr!=brandName.end();++itr){
        std::cout<<*itr;
    }

    
};
#endif // FUNCTIONALITIES_H

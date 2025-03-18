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
extern std::function<void(Container &data)> CreateObject;

/*
    Check Wheather the list is empty or not
*/
extern  std::function<bool (Container &data)> CheckIsEmpty;

/*
    Find and Return Average Product Price values for all products whose productType is provided as an argument
*/

extern std::function<float(Container &data, ProductType type)> AverageProductPriceByType;

/*
    Return productTaxAmount with the minimum productPrice 
*/
extern std::function<float(Container &data)> ProductTaxAmountMinimumProductPrice;

/*
    Return a Container of First N instances of product where N is given as input
*/
extern std::function<Container(Container &data,int N)> ReturnNInstancesOfProduct;

/*
    Identify and Return Unique productBrands
*/

extern std::function<setContainer(Container &data)> UnqueProductBrand;

/*
    Return an Array Of 3 Integer where 3 positions indicate that

    count of FMCG productType
    count of DOMESTIC productOrigin
    count of Product Instances whose productPrice is >50
*/
extern std::function<std::array<int,3>(Container &data)> CountOf3Features;

/*
    Returns a container of Addresses for Product Instances whose ProductBrand Matches
*/

extern std::function <Container (Container &data,std::string brand)> AddressOfProductInstancesMatchProductBrand;

/*
    Demontrate The Functionalities
*/

extern std::function<void()> Demonstrate;
#endif // FUNCTIONALITIES_H

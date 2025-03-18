#include "Product.h"
std::ostream &operator<<(std::ostream &os, const Product &rhs) {
    os << "productId: " << rhs.productId
       << " productType: " <<DisplayProductType(rhs.productType)
       << " productPrice: " << rhs.productPrice
       << " productBrand: " << rhs.productBrand
       << " productOrigin: " <<DisplayProductOrigin(rhs.productOrigin)
       << " productTaxAmount: " << rhs.productTaxAmount;
    return os;
}

//Display the Enum type by passing an enum value

std::string DisplayProductType(ProductType type)
{
    if(ProductType::APPLIANCE==type){
        return "APPLIANCE";
    }else if(ProductType::PERFUME==type){
        return "PERFUME";
    }else{
        return "FMCG";
    }
}

//Display the Enum type by passing an enum value
std::string DisplayProductOrigin(ProductOrigin type)
{
    if(ProductOrigin::DOMESTIC==type){
        return "DOMESTIC";
    }else{
        return "IMPORTED";
    }
}

//@Parameterized Constructor by passing 6 argument
Product::Product(std::string productId, ProductType productType, float productPrice, std::string productBrand, ProductOrigin productOrigin, float productTaxAmount)
:productId(productId),productType(productType),productPrice(productPrice),productBrand(productBrand),productOrigin(productOrigin)
{
    this->productTaxAmount = 0.5*productPrice;
}

//@Destructor : for destroying the ___ object 
Product::~Product()
{
    std::cout<<"Product Destroyed\n";
}

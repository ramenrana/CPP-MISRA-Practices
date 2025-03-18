#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include "ProductType.h"
#include "ProductOrigin.h"

class Product
{
private:
    std::string productId;
    ProductType productType;
    float productPrice;
    std::string productBrand;
    ProductOrigin productOrigin;
    float productTaxAmount;
public:
    //@Default Constructor is disabled
    Product()=delete;

    //@Copy Constructor is disabled/enabled
    Product(Product &obj)=default;
    
    //@Move Constructor is disabled/enabled
    Product(Product &&obj)=delete;
    
    //@Parameterized Constructor by passing 6 argument
    Product(
        std::string productId,
        ProductType productType,
        float productPrice,
        std::string productBrand,
        ProductOrigin productOrigin,
        float productTaxAmount
    );
    
    //@Destructor : for destroying the ___ object 
    ~Product();
    
    //@Getter & Setter functions
    std::string getProductId() const { return productId; }
    void setProductId(const std::string &productId_) { productId = productId_; }
    
    ProductType getProductType() const { return productType; }
    void setProductType(const ProductType &productType_) { productType = productType_; }
    
    float getProductPrice() const { return productPrice; }
    void setProductPrice(float productPrice_) { productPrice = productPrice_; }
    
    std::string getProductBrand() const { return productBrand; }
    void setProductBrand(const std::string &productBrand_) { productBrand = productBrand_; }
    
    ProductOrigin getProductOrigin() const { return productOrigin; }
    void setProductOrigin(const ProductOrigin &productOrigin_) { productOrigin = productOrigin_; }
    
    float getProductTaxAmount() const { return productTaxAmount; }
    void setProductTaxAmount(float productTaxAmount_) { productTaxAmount = productTaxAmount_; }

    //overload ostream << operator for displaying the data member of this class
    friend std::ostream &operator<<(std::ostream &os, const Product &rhs);
    
    
    
};
//Display the Enum type by passing an enum value
std::string DisplayProductType(ProductType type);

std::string DisplayProductOrigin(ProductOrigin type);

#endif // PRODUCT_H

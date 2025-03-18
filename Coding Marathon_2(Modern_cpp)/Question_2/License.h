#ifndef LICENSE_H
#define LICENSE_H

#include <iostream>
#include "LicenseCatagory.h"

class License
{
private:
    std::string lincenseNumber;
    int licenseValidityYears;
    LicenceCatagory licenceCatagory;
    std::string licenceIssuingRTO;
    std::string licenseIssuingState;
public:
    //@Default Constructor is disabled
    License()=delete;
    
    //@Copy Constructor is disabled/enabled
    License(License &obj)=default;
    
    //@Move Constructor is disabled/enabled
    License(License &&obj)=delete;
    
    //@Parameterized Constructor by passing  __  argument
    License(
        std::string lincenseNumber,
        int licenseValidityYears,
        LicenceCatagory licenceCatagory,
        std::string licenceIssuingRTO,
        std::string licenseIssuingState
        );

    //@Destructor : for destroying the ___ object 
    ~License();

    //@Getter & Setter functions
    std::string getLincenseNumber() const { return lincenseNumber; }
    void setLincenseNumber(const std::string &lincenseNumber_) { lincenseNumber = lincenseNumber_; }

    int getLicenseValidityYears() const { return licenseValidityYears; }
    void setLicenseValidityYears(int licenseValidityYears_) { licenseValidityYears = licenseValidityYears_; }

    LicenceCatagory getLicenceCatagory() const { return licenceCatagory; }
    void setLicenceCatagory(const LicenceCatagory &licenceCatagory_) { licenceCatagory = licenceCatagory_; }

    std::string getLicenceIssuingRTO() const { return licenceIssuingRTO; }
    void setLicenceIssuingRTO(const std::string &licenceIssuingRTO_) { licenceIssuingRTO = licenceIssuingRTO_; }

    std::string getLicenseIssuingState() const { return licenseIssuingState; }
    void setLicenseIssuingState(const std::string &licenseIssuingState_) { licenseIssuingState = licenseIssuingState_; }

    
    //overload ostream << operator for displaying the data member of this class
    friend std::ostream &operator<<(std::ostream &os, const License &rhs);
    
};
//Display the Enum type by passing an enum value
std::string DisplayEnum(LicenceCatagory type);

#endif // LICENSE_H

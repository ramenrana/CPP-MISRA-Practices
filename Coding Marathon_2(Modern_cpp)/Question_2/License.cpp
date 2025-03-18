#include "License.h"

   //overload ostream << operator for displaying the data member of this class
std::ostream &operator<<(std::ostream &os, const License &rhs) {
    os << "lincenseNumber: " << rhs.lincenseNumber
       << " licenseValidityYears: " << rhs.licenseValidityYears
       << " licenceCatagory: " <<DisplayEnum( rhs.licenceCatagory)
       << " licenceIssuingRTO: " << rhs.licenceIssuingRTO
       << " licenseIssuingState: " << rhs.licenseIssuingState;
    return os;
}

//Display the Enum type by passing an enum value
std::string DisplayEnum(LicenceCatagory type)
{
    if(LicenceCatagory::COMMERCIAL==type){
        return "COMMERCIAL";
    }else if(LicenceCatagory::SPECIAL_PURPOSE==type){
        return "SPECIAL_PURPOSE";
    }else{
        return "PERSONAL";
    }
}

//@Parameterized Constructor by passing  __  argument
License::License(std::string lincenseNumber, int licenseValidityYears, LicenceCatagory licenceCatagory, std::string licenceIssuingRTO, std::string licenseIssuingState)
:lincenseNumber(lincenseNumber),licenceCatagory(licenceCatagory),licenceIssuingRTO(licenceIssuingRTO),licenseIssuingState(licenseIssuingState){
    if(licenseValidityYears>0 && licenseValidityYears<15){
        this->licenseValidityYears=licenseValidityYears;
    }
}

//@Destructor : for destroying the ___ object 
License::~License()
{
    std::cout<<"License Deleted\n";
}

#include "Employee.h"
std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_id: " << rhs._id
       << " _department: " <<DisplayEnum( rhs._department)
       << " _activeProject: " << *rhs._activeProject.get();
    return os;
}
std::string DisplayEnum(Department type)
{
    if(Department::DEVELOPMENT==type){
        return "DEVELOPEMENT";
    }else if(Department::INTEGRATION==type){
        return "INTEGRATION";
    }else{
        return "TESTING";
    }
}

Employee::Employee(std::string _id, Department _department, pointer _activeProject)
:_id(_id),_department(_department),_activeProject(_activeProject){
}

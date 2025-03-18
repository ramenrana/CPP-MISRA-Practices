#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include "Department.h"
#include "ActiveProject.h"
#include <memory>

using pointer = std::shared_ptr<ActiveProject>;

class Employee
{
private:
    std::string _id;
    Department _department;
    pointer _activeProject;
public:
    /// @brief Default Constructot Disable
    Employee()=delete;

    /// @brief Copy Constructor Enabled
    /// @param obj 
    Employee(Employee &obj)=default;

    /// @brief Move Constructor Disabled
    /// @param obj 
    Employee(Employee &&obj)=delete;

    /// @brief Parameterized Constructor
    /// @param _projectName 
    /// @param _projectTeamCount 
    /// @param _projectCost 
    /// @param _projectDuration 
    Employee(
        std::string _id,
        Department _department,
        pointer _activeProject
    );

    /// @brief Destructor Enabled
    ~Employee()=default;


    /// @brief Getter Setter Function

    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    Department department() const { return _department; }
    void setDepartment(const Department &department) { _department = department; }

    pointer activeProject() const { return _activeProject; }
    void setActiveProject(const pointer &activeProject) { _activeProject = activeProject; }

    /// @brief Overload << operator
    /// @param os 
    /// @param rhs 
    /// @return ostrem
    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
    
};

/// @brief Display Enum
/// @param type 
/// @return string
std::string DisplayEnum(Department type);
#endif // EMPLOYEE_H

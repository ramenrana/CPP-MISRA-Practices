#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include "Employee.h"
#include "ActiveProject.h"
#include "Department.h"
#include <vector>
#include <memory>
#include <optional>

using EmpPointer = std::shared_ptr<Employee>;
using Container = std::vector<EmpPointer>;

/*Create list of Object of Employee*/
void CreateObject(Container &data);

/*Return employee who follows this condition
    -_projectTeamCount at least 10
    -_projectCost <10000
    -_department DEVELOPEMENT OR TESTING
 */
std::optional<Container> ReturnEmployee(Container &data);

/*
    a function which conatin two lambda function
    -1) To display the employee at the index
    -2) Check if the container atleat 3 employee
*/
void LamdaFunctions(Container &data);

/*Average project cost for all employee whose depatment is DEVELOPEMENT*/
float Average(Container &data);

/*REturn all employee whose project duration is > 225*/
std::optional<Container> ReturnEmployeeWhoseDurationabove225(Container &data);

void Demonstrate();

#endif // FUNCTIONALITIES_H

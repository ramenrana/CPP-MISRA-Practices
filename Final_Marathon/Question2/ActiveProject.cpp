#include "ActiveProject.h"
std::ostream &operator<<(std::ostream &os, const ActiveProject &rhs) {
    os << "_projectName: " << rhs._projectName
       << " _projectTeamCount: " << rhs._projectTeamCount
       << " _projectCost: " << rhs._projectCost
       << " _projectDuration: " << rhs._projectDuration;
    return os;
}
ActiveProject::ActiveProject(std::string _projectName, int _projectTeamCount, float _projectCost, int _projectDuration)
:_projectName(_projectName),_projectTeamCount(_projectTeamCount),_projectCost(_projectCost),_projectDuration(_projectDuration){
}

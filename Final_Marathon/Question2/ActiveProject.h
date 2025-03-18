#ifndef ACTIVEPROJECT_H
#define ACTIVEPROJECT_H

#include <iostream>

class ActiveProject
{
private:
    std::string _projectName;
    int _projectTeamCount;
    float _projectCost;
    int _projectDuration;

public:
    /// @brief Default Constructot Disable
    ActiveProject()=delete;

    /// @brief Copy Constructor Enabled
    /// @param obj 
    ActiveProject(ActiveProject &obj)=default;

    /// @brief Move Constructor Disabled
    /// @param obj 
    ActiveProject(ActiveProject &&obj)=delete;

    /// @brief Parameterized Constructor
    /// @param _projectName 
    /// @param _projectTeamCount 
    /// @param _projectCost 
    /// @param _projectDuration 
    ActiveProject(
        std::string _projectName,
        int _projectTeamCount,
        float _projectCost,
        int _projectDuration
    );

    /// @brief Destructor Enabled
    ~ActiveProject()=default;

    /// @brief Getter Setter Function

    std::string projectName() const { return _projectName; }
    void setProjectName(const std::string &projectName) { _projectName = projectName; }

    int projectTeamCount() const { return _projectTeamCount; }
    void setProjectTeamCount(int projectTeamCount) { _projectTeamCount = projectTeamCount; }

    float projectCost() const { return _projectCost; }
    void setProjectCost(float projectCost) { _projectCost = projectCost; }

    int projectDuration() const { return _projectDuration; }
    void setProjectDuration(int projectDuration) { _projectDuration = projectDuration; }
    /// @brief Overload << operator
    /// @param os 
    /// @param rhs 
    /// @return ostrem
    friend std::ostream &operator<<(std::ostream &os, const ActiveProject &rhs);
    
};

#endif // ACTIVEPROJECT_H

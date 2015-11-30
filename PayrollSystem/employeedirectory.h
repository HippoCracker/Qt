#ifndef EMPLOYEEDIRECTORY_H
#define EMPLOYEEDIRECTORY_H

#include <vector>
#include "employee.h"

class EmployeeDirectory
{
public:
    EmployeeDirectory();
    ~EmployeeDirectory();

    vector<Employee*>* getEmployeeList();

    Employee* createEmployee();
    void deleteEmployee(Employee *employee);

private:
    vector<Employee*> *employeeList;
};

#endif // EMPLOYEEDIRECTORY_H

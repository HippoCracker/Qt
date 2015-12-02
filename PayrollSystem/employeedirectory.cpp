#include "employeedirectory.h"

EmployeeDirectory::EmployeeDirectory()
{
    employeeList = new vector<Employee*>();
}

EmployeeDirectory::~EmployeeDirectory()
{
    employeeList->clear();
    delete employeeList;
}

vector<Employee*>* EmployeeDirectory::getEmployeeList()
{
    return employeeList;
}

Employee* EmployeeDirectory::createEmployee()
{
    Employee* employee = new Employee();
    employeeList->push_back(employee);
    return employee;
}

Employee* EmployeeDirectory::findEmployeeById(int id)
{
    for (int i = 0; i < employeeList->size(); i++) {
        Employee *employee = employeeList->at(i);
        if (employee->getPerson()->getId() == id) {
            return employee;
        }
    }
}

void EmployeeDirectory::deleteEmployee(Employee *employee)
{
    for (int i = 0; i < employeeList->size(); i++) {
        if (employeeList->at(i) == employee) {
            employeeList->erase(employeeList->begin() + i);
            break;
        }
    }
}

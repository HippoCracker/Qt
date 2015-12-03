#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include "payrolldirectory.h"
#include "role.h"

class Employee
{
public:
    Employee();
    ~Employee();

    Person* getPerson();
    void setPerson(Person* person);

    double getSalaryPerUnit();
    void setSalaryPerUnit(double salary);

    QString getPayPeriod();
    void setPayPeriod(QString payPeriod);

    QString getDepartment();
    void setDepartment(QString department);

    double getWorkUnits();
    void setWorkUnits(double workUnits);

    PayrollDirectory* getPayrollDirectory();

private:
    Person* m_person;
    double m_salaryPerUnit;
    double m_workUnits;
    QString m_payPeriod;
    QString m_department;
    PayrollDirectory *payrollDirectory;
};

#endif // EMPLOYEE_H

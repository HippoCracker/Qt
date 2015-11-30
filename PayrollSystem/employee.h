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

//    enum EmployeeRole {
//        STUDENT, TEACHER, EXECUTIVE, STAFF, VOLUNTEER
//    };

    enum PayPeriod {
        HOUR, DAY, WEEK, BIWEEK, MONTH, YEAR
    };

    Person* getPerson();
    void setPerson(Person* person);

    double getSalaryPerUnit();
    void setSalaryPerUnit(double salary);

    PayPeriod* getPayPeriod();
    void setPayPeriod(PayPeriod* payPeriod);

    Role* getRole();
    void setRole(Role* role);

    double getWorkUnits();
    void setWorkUnits(double workUnits);

private:
    Person* m_person;
    double m_salaryPerUnit;
    double m_workUnits;
    PayPeriod* m_payPeriod;
    Role* m_role;
    PayrollDirectory *payrollDirectory;
};

#endif // EMPLOYEE_H

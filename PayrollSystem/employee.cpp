#include "employee.h"

Employee::Employee()
{
    payrollDirectory = new PayrollDirectory();
}

Employee::~Employee()
{

}

Person* Employee::getPerson()
{
    return m_person;
}

void Employee::setPerson(Person* person)
{
    m_person = person;
}

double Employee::getSalaryPerUnit()
{
    return m_salaryPerUnit;
}

void Employee::setSalaryPerUnit(double salary)
{
    m_salaryPerUnit = salary;
}

Employee::PayPeriod* Employee::getPayPeriod()
{
    return m_payPeriod;
}

void Employee::setPayPeriod(Employee::PayPeriod* payPeriod)
{
    m_payPeriod = payPeriod;
}

Role* Employee::getRole()
{
    return m_role;
}

void Employee::setRole(Role* role)
{
    m_role = role;
}

double Employee::getWorkUnits()
{
    return m_workUnits;
}

void Employee::setWorkUnits(double workUnits)
{
    m_workUnits = workUnits;
}

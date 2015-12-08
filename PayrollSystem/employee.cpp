#include "employee.h"

Employee::Employee()
{
    payrollDirectory = new PayrollDirectory();
    dailyRecordCatalog = new DailyRecordCatalog();
}

Employee::~Employee()
{
    delete m_person;
    delete payrollDirectory;
    delete dailyRecordCatalog;
}

Person* Employee::getPerson()
{
    return m_person;
}

void Employee::setPerson(Person* person)
{
    m_person = person;
}

DailyRecordCatalog* Employee::getDailyRecordCatalog()
{
    return dailyRecordCatalog;
}

double Employee::getSalaryPerUnit()
{
    return m_salaryPerUnit;
}

void Employee::setSalaryPerUnit(double salary)
{
    m_salaryPerUnit = salary;
}

QString Employee::getPayPeriod()
{
    return m_payPeriod;
}

void Employee::setPayPeriod(QString payPeriod)
{
    m_payPeriod = payPeriod;
}

double Employee::getWorkUnits()
{
    return m_workUnits;
}

void Employee::setWorkUnits(double workUnits)
{
    m_workUnits = workUnits;
}

PayrollDirectory* Employee::getPayrollDirectory()
{
    return payrollDirectory;
}

QString Employee::getDepartment()
{
    return m_department;
}

void Employee::setDepartment(QString department)
{
    m_department = department;
}

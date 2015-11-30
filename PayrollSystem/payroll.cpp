#include "payroll.h"

Payroll::Payroll()
{

}

Payroll::~Payroll()
{

}

QDateTime Payroll::getStartDate()
{
    return m_startDate;
}

void Payroll::setStartDate(QDateTime date)
{
    m_startDate = date;
}

QDateTime Payroll::getEndDate()
{
    return m_endDate;
}

void Payroll::setEndDate(QDateTime date)
{
    m_endDate = date;
}

double Payroll::getWorkUnits()
{
    return m_workUnits;
}

void Payroll::setWorkUnits(double workUnits)
{
    m_workUnits = workUnits;
}

double Payroll::getSalaryPerUnit()
{
    return m_salaryPerUnit;
}

void Payroll::setSalaryPerUnit(double salary)
{
    m_salaryPerUnit = salary;
}

double Payroll::getTotalSalary()
{
    return m_salaryPerUnit * m_workUnits;
}


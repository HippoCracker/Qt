#ifndef PAYROLL_H
#define PAYROLL_H

#include <QDateTime>

class Payroll
{
public:
    Payroll();
    ~Payroll();

    QDateTime getStartDate();
    void setStartDate(QDateTime date);

    QDateTime getEndDate();
    void setEndDate(QDateTime date);

    double getWorkUnits();
    void setWorkUnits(double workUnits);

    double getSalaryPerUnit();
    void setSalaryPerUnit(double salary);

    double getTotalSalary();

private:
    QDateTime m_startDate;
    QDateTime m_endDate;
    double m_workUnits;
    double m_salaryPerUnit;
    double m_totalSalary;
};

#endif // PAYROLL_H

#ifndef PAYROLL_H
#define PAYROLL_H

#include <QDateTime>

class Payroll
{
public:
    Payroll();
    ~Payroll();

    QDate* getStartDate();
    void setStartDate(QDate* date);

    QDate* getEndDate();
    void setEndDate(QDate* date);

    double getWorkUnits();
    void setWorkUnits(double workUnits);

    double getSalaryPerUnit();
    void setSalaryPerUnit(double salary);

    double getTotalSalary();

private:
    QDate* m_startDate;
    QDate* m_endDate;
    double m_workUnits;
    double m_salaryPerUnit;
    double m_totalSalary;
};

#endif // PAYROLL_H

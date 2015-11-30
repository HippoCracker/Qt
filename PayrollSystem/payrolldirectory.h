#ifndef PAYROLLDIRECTORY_H
#define PAYROLLDIRECTORY_H

#include <vector>
#include "payroll.h"

using namespace std;

class PayrollDirectory
{
public:
    PayrollDirectory();
    ~PayrollDirectory();

    vector<Payroll*>* getPayrollList();
    Payroll* createPayroll();
    void deletePayroll(Payroll* payroll);


private:
    vector<Payroll*> *payrollList;
};

#endif // PAYROLLDIRECTORY_H

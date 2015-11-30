#include "payrolldirectory.h"

PayrollDirectory::PayrollDirectory()
{
    payrollList = new vector<Payroll*>();
}

PayrollDirectory::~PayrollDirectory()
{
    payrollList->clear();
    delete payrollList;
}


vector<Payroll*>* PayrollDirectory::getPayrollList()
{
    return payrollList;
}

Payroll* PayrollDirectory::createPayroll()
{
    Payroll *payroll = new Payroll();
    payrollList->push_back(payroll);
    return payroll;
}

void PayrollDirectory::deletePayroll(Payroll* payroll)
{
    for (int i = 0; i < payrollList->size(); i++) {
        if (payrollList->at(i) == payroll) {
            payrollList->erase(payrollList->begin() + i);
            break;
        }
    }
}

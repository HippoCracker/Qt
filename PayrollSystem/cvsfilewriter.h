#ifndef CVSFILEWRITER_H
#define CVSFILEWRITER_H

#include "employeedirectory.h"
#include "payrolldirectory.h"

class CvsFileWriter
{
public:
    CvsFileWriter();

    void writeEmployeesToFile(EmployeeDirectory* employeeDirectory, QString dir);
    void writePayrollsToFile(PayrollDirectory* payrollDirectory, QString dir);

};

#endif // CVSFILEWRITER_H

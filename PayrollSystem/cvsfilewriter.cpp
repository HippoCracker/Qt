#include "cvsfilewriter.h"
#include <QFile>
#include <QTextStream>

CvsFileWriter::CvsFileWriter()
{

}


void CvsFileWriter::writeEmployeesToFile(EmployeeDirectory* employeeDirectory, QString dir)
{
    QFile file(dir);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);

        vector<Employee*>* employeeList = employeeDirectory->getEmployeeList();

        for (int i = 0; i < employeeList->size(); i++) {
            Employee *employee = employeeList->at(i);
            Person *person = employee->getPerson();

            stream << person->getFirstName() 	   << ","
                   << person->getLastName()  	   << ","
                   << person->getRole()		 	   << ","
                   << person->getAge()       	   << ","
                   << person->getPhoneNum()        << ","
                   << employee->getDepartment()    << ","
                   << employee->getPayPeriod()     << ","
                   << employee->getSalaryPerUnit() << endl;
        }

        file.close();
    }
}

void CvsFileWriter::writePayrollsToFile(PayrollDirectory* payrollDirectory, QString dir)
{
    QFile file(dir);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);

        vector<Payroll*>* payrollList = payrollDirectory->getPayrollList();

        for (int i = 0; i < payrollList->size(); i++) {
            Payroll *payroll = payrollList->at(i);

            stream << payroll->getStartDate().toString() << ","
                   << payroll->getEndDate().toString()   << ","
                   << payroll->getWorkUnits() 			 << ","
                   << payroll->getTotalSalary() 		 << endl;
        }

        file.close();
    }
}

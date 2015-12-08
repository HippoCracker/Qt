#include "cvsfilereader.h"
#include "QFile"
#include "personfactory.h"

CvsFileReader::CvsFileReader()
{

}


void CvsFileReader::readToEmployeeDirectory(EmployeeDirectory* employeeDirectory, QString dir)
{
    PersonFactory personFactory;

    QFile file(dir);
    file.open(QIODevice::ReadOnly);

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        QList<QByteArray> items = line.split(',');

        Person *person = personFactory.getPerson(items.at(2));
        person->setFirstName(items.at(0));
        person->setLastName(items.at(1));
        person->setAge(items.at(3).toInt());
        person->setPhoneNum(items.at(4));

        Employee* employee = employeeDirectory->createEmployee();
        employee->setPerson(person);
        employee->setDepartment(items.at(5));
        employee->setPayPeriod(items.at(6));
        employee->setSalaryPerUnit(items.at(7).toDouble());
    }
    file.close();
}

void CvsFileReader::readToDailyRecordCatalog(DailyRecordCatalog* dailyRecordCatalog, QString dir)
{
    QFile file(dir);
    file.open(QIODevice::ReadOnly);

    while(!file.atEnd()) {
        QByteArray line = file.readLine();
        QList<QByteArray> items = line.split(',');

        int year = items.at(0).toInt();
        int month = items.at(1).toInt();
        int day = items.at(2).toInt();

        int startHour = items.at(3).toInt();
        int startMin = items.at(4).toInt();

        int endHour = items.at(5).toInt();
        int endMin = items.at(6).toInt();

        bool isPay = (items.at(7) == "true" ? true : false);

        DailyRecord *dailyRecord = dailyRecordCatalog->createDailyRecord();

        dailyRecord->setDate(new QDate(year, month, day));
        dailyRecord->setStartTime(new QTime(startHour, startMin));
        dailyRecord->setEndTime(new QTime(endHour, endMin));
        dailyRecord->setIsPay(isPay);
    }

    file.close();
}

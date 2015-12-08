#ifndef CVSFILEREADER_H
#define CVSFILEREADER_H

#include "employeedirectory.h"
#include "dailyrecordcatalog.h"

class CvsFileReader
{
public:
    CvsFileReader();

    void readToEmployeeDirectory(EmployeeDirectory* employeeDirectory, QString dir);
    void readToDailyRecordCatalog(DailyRecordCatalog* dailyRecordCatalog, QString dir);
};

#endif // CVSFILEREADER_H

#include "dailyrecord.h"

DailyRecord::DailyRecord()
{

}

QDate* DailyRecord::getDate()
{
    return date;
}

void DailyRecord::setDate(QDate* d)
{
    date = d;
}

QTime* DailyRecord::getStartTime()
{
    return startTime;
}

void DailyRecord::setStartTime(QTime* dateTime)
{
    startTime = dateTime;
}

QTime* DailyRecord::getEndTime()
{
    return endTime;
}

void DailyRecord::setEndTime(QTime* dateTime)
{
    endTime = dateTime;
}

double DailyRecord::getWorkHours()
{
    int millisecInterval = startTime->msecsTo(*endTime);
    double hours = millisecInterval / (3600.0 * 1000);
    return hours;
}

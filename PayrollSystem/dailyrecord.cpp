#include "dailyrecord.h"

int DailyRecord::count = 0;

DailyRecord::DailyRecord()
{
    id = count++;
}

int DailyRecord::getId()
{
    return id;
}

QDate DailyRecord::getDate()
{
    return date;
}

void DailyRecord::setDate(QDate d)
{
    date = d;
}

bool DailyRecord::getIsPay()
{
    return isPay;
}

void DailyRecord::setIsPay(bool flag)
{
    isPay = flag;
}

QTime DailyRecord::getStartTime()
{
    return startTime;
}

void DailyRecord::setStartTime(QTime dateTime)
{
    startTime = dateTime;
}

QTime DailyRecord::getEndTime()
{
    return endTime;
}

void DailyRecord::setEndTime(QTime dateTime)
{
    endTime = dateTime;
}

double DailyRecord::getBonus()
{
    return bonus;
}

void DailyRecord::setBonus(double b)
{
    bonus = b;
}

double DailyRecord::getWorkHours()
{
    int millisecInterval = startTime.msecsTo(endTime);
    double hours = millisecInterval / (3600.0 * 1000);
    return hours;
}

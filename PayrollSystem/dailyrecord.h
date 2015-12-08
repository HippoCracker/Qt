#ifndef DAILYRECORD_H
#define DAILYRECORD_H

#include "QTime"

class DailyRecord
{
public:
    DailyRecord();
    ~DailyRecord();

    QDate* getDate();
    void setDate(QDate* d);

    QTime* getStartTime();
    void setStartTime(QTime* dateTime);

    QTime* getEndTime();
    void setEndTime(QTime* dateTime);

    double getWorkHours();


private:
    QTime* startTime;
    QTime* endTime;
    QDate* date;
};

#endif // DAILYRECORD_H

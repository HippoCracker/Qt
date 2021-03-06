#ifndef DAILYRECORD_H
#define DAILYRECORD_H

#include "QTime"

class DailyRecord
{
public:
    DailyRecord();
    ~DailyRecord();

    int getId();

    QDate getDate();
    void setDate(QDate d);

    bool getIsPay();
    void setIsPay(bool flag);

    QTime getStartTime();
    void setStartTime(QTime dateTime);

    QTime getEndTime();
    void setEndTime(QTime dateTime);

    double getBonus();
    void setBonus(double b);

    double getWorkHours();


private:
    static int count;

    int id;
    QTime startTime;
    QTime endTime;
    QDate date;
    double bonus;
    bool isPay;
};

#endif // DAILYRECORD_H

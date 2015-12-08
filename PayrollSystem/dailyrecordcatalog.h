#ifndef DAILYRECORDCATALOG_H
#define DAILYRECORDCATALOG_H

#include "dailyrecord.h"
#include <vector>

using namespace std;

class DailyRecordCatalog
{
public:
    DailyRecordCatalog();
    ~DailyRecordCatalog();

    DailyRecord* createDailyRecord();
    vector<DailyRecord*>* getDailyRecordList();

//    vector<DailyRecord*>* getDailyRecordsByDates(QDate start, QDate end);


private:
    vector<DailyRecord*> *dailyRecordList;
};

#endif // DAILYRECORDCATALOG_H

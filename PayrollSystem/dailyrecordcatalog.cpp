#include "dailyrecordcatalog.h"
#include "QDate"

DailyRecordCatalog::DailyRecordCatalog()
{
    dailyRecordList = new vector<DailyRecord*>();
}

DailyRecordCatalog::~DailyRecordCatalog()
{
    dailyRecordList->clear();
    delete dailyRecordList;
}


DailyRecord* DailyRecordCatalog::createDailyRecord()
{
    DailyRecord *dailyRecord = new DailyRecord();
    dailyRecordList->push_back(dailyRecord);
    return dailyRecord;
}

bool compare(DailyRecord& record1, DailyRecord& record2)
{
    return record1.getDate() < record2.getDate();
}

vector<DailyRecord*>* DailyRecordCatalog::getDailyRecordList()
{
    return dailyRecordList;
}

//vector<DailyRecord*>* DailyRecordCatalog::getDailyRecordsByDates(QDate start, QDate end)
//{
//    std::sort(dailyRecordList->begin(), dailyRecordList->end(), compare);
//    vector<DailyRecord*> *records = new vector<DailyRecord*>();
//    bool isInRange = false;
//    for (int i = 0; i < dailyRecordList->size(); i++) {
//        QDate date = dailyRecordList->at(i)->getDate();
//        if (date.operator ==(start)) {
//            isInRange = true;
//        }
//        if (date.operator ==(end)) {
//            isInRange = false;
//            break;
//        }

//        if(isInRange) {
//            records->push_back(dailyRecordList->at(i));
//        }
//    }

//    return records;
//}

#ifndef VIEWEMPLOYEEDIALOG_H
#define VIEWEMPLOYEEDIALOG_H

#include <QDialog>
#include "employee.h"

namespace Ui {
class ViewEmployeeDialog;
}

class ViewEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewEmployeeDialog(QWidget *parent = 0, Employee *e = 0);
    ~ViewEmployeeDialog();


public slots:
    void addBtnClicked();
    void startDateTxtFocused();
    void getStartDate();
    void back();
    void refreshTable(QString model);
    void loadBtnClicked();
    void exportBtnClicked();
    void getLoadDirectory(QString);
    void getExportDirectory(QString);
    void makePayment();


private:
    Ui::ViewEmployeeDialog *ui;
    Employee *employee;
    QDate startDate;
    QDate endDate;
    QSet<QDate> *holidaySet;

    void init();
    bool isHoliday(QDate* date);
    void displayPayrolls();
    void displayDailyRecord();
    void enableRecordsUI(bool isEnabled);
    void generatePayroll(vector<DailyRecord*>* records);
    double getWorkUnitsByDailyRecords(vector<DailyRecord*>* records);
    DailyRecord* findNewestRecord(vector<DailyRecord*>* records);
    DailyRecord* findOldestRecord(vector<DailyRecord*>* records);
};

#endif // VIEWEMPLOYEEDIALOG_H

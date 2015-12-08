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


private:
    Ui::ViewEmployeeDialog *ui;
    Employee *employee;
    QDate startDate;
    QDate endDate;

    void init();
    void displayPayrolls();
    void displayDailyRecord();
    void enableRecordsUI(bool isEnabled);
};

#endif // VIEWEMPLOYEEDIALOG_H

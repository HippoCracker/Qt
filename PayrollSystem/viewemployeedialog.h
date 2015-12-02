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
    void endDateTxtFocused();
    void getStartDate();
    void getEndDate();
    void back();

private:
    Ui::ViewEmployeeDialog *ui;
    Employee *employee;
    QDate startDate;
    QDate endDate;

    void refreshTable();

};

#endif // VIEWEMPLOYEEDIALOG_H

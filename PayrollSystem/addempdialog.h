#ifndef ADDEMPDIALOG_H
#define ADDEMPDIALOG_H

#include <QDialog>
#include "employeedirectory.h"

namespace Ui {
class AddEmpDialog;
}

class AddEmpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddEmpDialog(QWidget *parent = 0, EmployeeDirectory *ed = 0);
    ~AddEmpDialog();

public slots:
    void createBtnClicked();
    void backBtnClicked();

private:
    Ui::AddEmpDialog *ui;
    EmployeeDirectory *employeeDirectory;
    void init();

};

#endif // ADDEMPDIALOG_H

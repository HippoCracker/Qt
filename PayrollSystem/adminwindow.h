#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include "employeedirectory.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = 0);
    ~AdminWindow();

public slots:
    void viewBtnClicked();
    void loadBtnClicked();
    void refreshBtnClicked();
    void exportBtnClicked();
    void addEmpBtnClicked();
    void refreshTable();
    void getLoadDirectory(QString dir);
    void getExportDirectory(QString dir);

private:
    Ui::AdminWindow *ui;
    EmployeeDirectory *employeeDirectory;
};

#endif // ADMINWINDOW_H

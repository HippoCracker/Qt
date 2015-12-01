#ifndef EMPLOYEEWINDOW_H
#define EMPLOYEEWINDOW_H

#include <QMainWindow>

namespace Ui {
class EmployeeWindow;
}

class EmployeeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EmployeeWindow(QWidget *parent = 0);
    ~EmployeeWindow();

private:
    Ui::EmployeeWindow *ui;
};

#endif // EMPLOYEEWINDOW_H

#include "employeewindow.h"
#include "ui_employeewindow.h"

EmployeeWindow::EmployeeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EmployeeWindow)
{
    ui->setupUi(this);
}

EmployeeWindow::~EmployeeWindow()
{
    delete ui;
}

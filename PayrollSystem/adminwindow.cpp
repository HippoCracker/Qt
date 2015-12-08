#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "viewemployeedialog.h"
#include "addempdialog.h"
#include "employeerole.h"
#include "employee.h"
#include "student.h"
#include "directorydialog.h"
#include "cvsfilereader.h"
#include "cvsfilewriter.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    employeeDirectory = new EmployeeDirectory();

    Person *person = new Student();
    person->setFirstName("Zesheng");
    person->setLastName("Zong");
    person->setAge(20);
    person->setPhoneNum("111-1111");

    Employee *employee = employeeDirectory->createEmployee();
    employee->setWorkUnits(10);
    employee->setSalaryPerUnit(20);
    employee->setPayPeriod("month");
    employee->setPerson(person);

    ui->errorLabel->hide();


    connect(ui->viewBtn, SIGNAL(clicked(bool)), this, SLOT(viewBtnClicked()));
    connect(ui->loadBtn, SIGNAL(clicked(bool)), this, SLOT(loadBtnClicked()));
    connect(ui->refreshBtn, SIGNAL(clicked(bool)), this, SLOT(refreshBtnClicked()));
    connect(ui->exportBtn, SIGNAL(clicked(bool)), this, SLOT(exportBtnClicked()));
    connect(ui->addEmpBtn, SIGNAL(clicked(bool)), this, SLOT(addEmpBtnClicked()));

    refreshTable();
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::refreshTable()
{
    ui->employeeTable->clear();
    ui->employeeTable->setRowCount(0);

    vector<Employee*> *employeeList = employeeDirectory->getEmployeeList();
    for (int i = 0; i < employeeList->size(); i++) {
        Employee *employee = employeeList->at(i);
        ui->employeeTable->insertRow(i);
        QTableWidgetItem *id = new QTableWidgetItem(QString::number(employee->getPerson()->getId()));
        QTableWidgetItem *fname = new QTableWidgetItem(employee->getPerson()->getFirstName());
        QTableWidgetItem *lname = new QTableWidgetItem(employee->getPerson()->getLastName());
        QTableWidgetItem *payPeriod = new QTableWidgetItem(employee->getPayPeriod());
        QTableWidgetItem *role = new QTableWidgetItem(employee->getPerson()->getRole());

        ui->employeeTable->setItem(i, 0, id);
        ui->employeeTable->setItem(i, 1, fname);
        ui->employeeTable->setItem(i, 2, lname);
        ui->employeeTable->setItem(i, 3, payPeriod);
        ui->employeeTable->setItem(i, 4, role);
    }

    ui->employeeTable->setHorizontalHeaderLabels(QStringList() << "ID"
                                                 << "First Name"
                                                 << "Last Name"
                                                 << "Pay Period"
                                                 << "Role");
}

void AdminWindow::viewBtnClicked()
{
    QItemSelectionModel *selectModel = ui->employeeTable->selectionModel();

    if (selectModel->hasSelection()) {
        QModelIndexList indexList = selectModel->selectedRows();
        QTableWidgetItem *item = ui->employeeTable->item(indexList.at(0).row(), 0);


        int id = item->text().toInt();

        Employee *employee = employeeDirectory->findEmployeeById(id);



        ViewEmployeeDialog viewEmployeeDialog(0, employee);
        viewEmployeeDialog.exec();
    } else {
        ui->errorLabel->setText("Please select one employee.");
        ui->errorLabel->show();
    }
}

void AdminWindow::addEmpBtnClicked()
{
    AddEmpDialog addEmpDialog(0, employeeDirectory);
    addEmpDialog.exec();
}

void AdminWindow::loadBtnClicked()
{
    DirectoryDialog directoryDialog(this);
    connect(&directoryDialog, SIGNAL(output(QString)), this, SLOT(getLoadDirectory(QString)));
    directoryDialog.exec();
}

void AdminWindow::getLoadDirectory(QString dir)
{
    QString directory = dir;

    CvsFileReader fileReader;
    fileReader.readToEmployeeDirectory(employeeDirectory, dir);
}

void AdminWindow::refreshBtnClicked()
{
    refreshTable();
}

void AdminWindow::exportBtnClicked()
{
    DirectoryDialog directoryDialog(this);
    connect(&directoryDialog, SIGNAL(output(QString)), this, SLOT(getExportDirectory(QString)));
    directoryDialog.exec();
}

void AdminWindow::getExportDirectory(QString dir)
{
    QString directory = dir;
}

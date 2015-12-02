#include "viewemployeedialog.h"
#include "ui_viewemployeedialog.h"

ViewEmployeeDialog::ViewEmployeeDialog(QWidget *parent, Employee *e) :
    QDialog(parent),
    ui(new Ui::ViewEmployeeDialog),
    employee(e)
{
    ui->setupUi(this);

    ui->empIdLabel->setText(QString::number(employee->getPerson()->getId()));
    ui->empNameLabel->setText(employee->getPerson()->getFirstName() + " " +
                              employee->getPerson()->getLastName());
    ui->payPeriodLabel->setText(employee->getPayPeriod());
    ui->roleLabel->setText(employee->getRole()->toString());

    QString salaryPerUnit = QString::number(employee->getSalaryPerUnit());
    ui->salaryPerUnitTxt->setText(salaryPerUnit);

    ui->salaryPerUnitTxt->setEnabled(false);
    ui->startCalendar->hide();
    ui->endCalendar->hide();

    connect(ui->addBtn, SIGNAL(clicked(bool)), this, SLOT(addBtnClicked()));
    connect(ui->startDateTxt, SIGNAL(textEdited(QString)), this, SLOT(startDateTxtFocused()));
    connect(ui->endDateTxt, SIGNAL(textEdited(QString)), this, SLOT(endDateTxtFocused()));
    connect(ui->startCalendar, SIGNAL(clicked(QDate)), this, SLOT(getStartDate()));
    connect(ui->endCalendar, SIGNAL(clicked(QDate)), this, SLOT(getEndDate()));
    connect(ui->backBtn, SIGNAL(clicked(bool)), this, SLOT(back()));

    refreshTable();
}

ViewEmployeeDialog::~ViewEmployeeDialog()
{
    delete ui;
}

void ViewEmployeeDialog::addBtnClicked()
{
    QString start = ui->startDateTxt->text();
    QString end = ui->endDateTxt->text();
    QString workUnits = ui->workUnitsTxt->text();
    QString salaryPerUnit = ui->salaryPerUnitTxt->text();


    PayrollDirectory *payrollDirectory = employee->getPayrollDirectory();
    Payroll *payroll = payrollDirectory->createPayroll();
    payroll->setStartDate(&startDate);
    payroll->setEndDate(&endDate);
    payroll->setWorkUnits(workUnits.toDouble());
    payroll->setSalaryPerUnit(salaryPerUnit.toDouble());

    refreshTable();
}

void ViewEmployeeDialog::refreshTable()
{
    ui->empPayrollTable->clear();

    PayrollDirectory *payrollDirectory = employee->getPayrollDirectory();
    vector<Payroll*> *payrollList = payrollDirectory->getPayrollList();

    for (int i = 0; i < payrollList->size(); i++) {
        Payroll* payroll = payrollList->at(i);
        ui->empPayrollTable->insertRow(i);
        QTableWidgetItem *startDate = new QTableWidgetItem(payroll->getStartDate()->toString());
        QTableWidgetItem *endDate = new QTableWidgetItem(payroll->getEndDate()->toString());
        QTableWidgetItem *workUnits = new QTableWidgetItem(QString::number(payroll->getWorkUnits()));
        QTableWidgetItem *salaryPerUnit = new QTableWidgetItem(QString::number(payroll->getSalaryPerUnit()));
        QTableWidgetItem *totalSalary = new QTableWidgetItem(QString::number(payroll->getTotalSalary()));

        ui->empPayrollTable->setItem(i, 0, startDate);
        ui->empPayrollTable->setItem(i, 1, endDate);
        ui->empPayrollTable->setItem(i, 2, workUnits);
        ui->empPayrollTable->setItem(i, 3, salaryPerUnit);
        ui->empPayrollTable->setItem(i, 4, totalSalary);
    }
}

void ViewEmployeeDialog::startDateTxtFocused()
{
    ui->startCalendar->show();
}

void ViewEmployeeDialog::endDateTxtFocused()
{
    ui->endCalendar->show();
}

void ViewEmployeeDialog::getStartDate()
{
    startDate = ui->startCalendar->selectedDate();
    ui->startDateTxt->setText(startDate.toString());
    ui->startCalendar->hide();
}

void ViewEmployeeDialog::getEndDate()
{
    endDate = ui->endCalendar->selectedDate();
    ui->endDateTxt->setText(endDate.toString());
    ui->endCalendar->hide();
}

void ViewEmployeeDialog::back()
{
    QDialog::reject();
}

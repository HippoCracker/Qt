#include "viewemployeedialog.h"
#include "ui_viewemployeedialog.h"
#include "directorydialog.h"
#include "cvsfilereader.h"

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
    ui->roleLabel->setText(employee->getPerson()->getRole());

    QString salaryPerUnit = QString::number(employee->getSalaryPerUnit());
    ui->salaryPerUnitTxt->setText(salaryPerUnit);

    ui->salaryPerUnitTxt->setEnabled(false);
    ui->startCalendar->hide();

    connect(ui->addBtn, SIGNAL(clicked(bool)), this, SLOT(addBtnClicked()));
    connect(ui->startDateTxt, SIGNAL(textEdited(QString)), this, SLOT(startDateTxtFocused()));
    connect(ui->startCalendar, SIGNAL(clicked(QDate)), this, SLOT(getStartDate()));
    connect(ui->backBtn, SIGNAL(clicked(bool)), this, SLOT(back()));
    connect(ui->displayCombo, SIGNAL(currentTextChanged(QString)), this, SLOT(refreshTable(QString)));
    connect(ui->loadBtn, SIGNAL(clicked(bool)), this, SLOT(loadBtnClicked()));
    connect(ui->exportBtn, SIGNAL(clicked(bool)), this, SLOT(exportBtnClicked()));

    init();
}

ViewEmployeeDialog::~ViewEmployeeDialog()
{
    delete ui;
}

void ViewEmployeeDialog::refreshTable(QString model)
{
    if (model == "Payroll") {
        displayPayrolls();
    } else {
        displayDailyRecord();
    }
}

void ViewEmployeeDialog::addBtnClicked()
{
    QString workUnits = ui->workUnitsTxt->text();
    QString salaryPerUnit = ui->salaryPerUnitTxt->text();


    PayrollDirectory *payrollDirectory = employee->getPayrollDirectory();
    Payroll *payroll = payrollDirectory->createPayroll();

    payroll->setStartDate(startDate);
    payroll->setEndDate(endDate);
    payroll->setWorkUnits(workUnits.toDouble());
    payroll->setSalaryPerUnit(salaryPerUnit.toDouble());

}

void ViewEmployeeDialog::displayPayrolls()
{
    ui->empPayrollTable->clear();
    ui->empPayrollTable->setRowCount(0);

    PayrollDirectory *payrollDirectory = employee->getPayrollDirectory();
    vector<Payroll*> *payrollList = payrollDirectory->getPayrollList();

    for (int i = 0; i < payrollList->size(); i++) {
        Payroll* payroll = payrollList->at(i);
        ui->empPayrollTable->insertRow(i);
        QTableWidgetItem *startDate = new QTableWidgetItem(payroll->getStartDate().toString());
        QTableWidgetItem *endDate = new QTableWidgetItem(payroll->getEndDate().toString());
        QTableWidgetItem *workUnits = new QTableWidgetItem(QString::number(payroll->getWorkUnits()));
        QTableWidgetItem *salaryPerUnit = new QTableWidgetItem(QString::number(payroll->getSalaryPerUnit()));
        QTableWidgetItem *totalSalary = new QTableWidgetItem(QString::number(payroll->getTotalSalary()));

        ui->empPayrollTable->setItem(i, 0, startDate);
        ui->empPayrollTable->setItem(i, 1, endDate);
        ui->empPayrollTable->setItem(i, 2, workUnits);
        ui->empPayrollTable->setItem(i, 3, salaryPerUnit);
        ui->empPayrollTable->setItem(i, 4, totalSalary);
    }
    ui->empPayrollTable->setHorizontalHeaderLabels(QStringList() << "Start Date"
                                                 << "End Date"
                                                 << "Work Units"
                                                 << "Salary Per Unit"
                                                 << "Total Salary");
    enableRecordsUI(false);
}

void ViewEmployeeDialog::displayDailyRecord()
{
    ui->empPayrollTable->clear();
    ui->empPayrollTable->setRowCount(0);

    vector<DailyRecord*>* records = employee->getDailyRecordCatalog()->getDailyRecordList();

    for (int i = 0; i < records->size(); i++) {
        DailyRecord *dailyRecord = records->at(i);
        ui->empPayrollTable->insertRow(i);

        double hours = dailyRecord->getWorkHours();
        double salaryPerUnit = employee->getSalaryPerUnit();
        double totalSalary = hours * salaryPerUnit;

        QTableWidgetItem *date = new QTableWidgetItem(dailyRecord->getDate()->toString());
        QTableWidgetItem *startTime = new QTableWidgetItem(dailyRecord->getStartTime()->toString());
        QTableWidgetItem *endTime = new QTableWidgetItem(dailyRecord->getEndTime()->toString());
        QTableWidgetItem *workUnits = new QTableWidgetItem(QString::number(hours));
        QTableWidgetItem *total = new QTableWidgetItem(QString::number(totalSalary));

        ui->empPayrollTable->setItem(i, 0, date);
        ui->empPayrollTable->setItem(i, 1, startTime);
        ui->empPayrollTable->setItem(i, 2, endTime);
        ui->empPayrollTable->setItem(i, 3, workUnits);
        ui->empPayrollTable->setItem(i, 4, total);

    }

    ui->empPayrollTable->setHorizontalHeaderLabels(QStringList() << "Date"
                                                 << "Start Time"
                                                 << "End Time"
                                                 << "Work Units"
                                                 << "Total Salary");


    enableRecordsUI(true);
}

void ViewEmployeeDialog::enableRecordsUI(bool isEnabled)
{
    ui->addBtn->setEnabled(isEnabled);
    ui->endTimeEdit->setEnabled(isEnabled);
    ui->salaryPerUnitTxt->setEnabled(isEnabled);
    ui->startDateTxt->setEnabled(isEnabled);
    ui->startTimeEdit->setEnabled(isEnabled);
    ui->endTimeEdit->setEnabled(isEnabled);
    ui->payBtn->setEnabled(!isEnabled);
}

void ViewEmployeeDialog::startDateTxtFocused()
{
    ui->startCalendar->show();
}

void ViewEmployeeDialog::getStartDate()
{
    startDate = ui->startCalendar->selectedDate();
    ui->startDateTxt->setText(startDate.toString());
    ui->startCalendar->hide();
}

void ViewEmployeeDialog::back()
{
    QDialog::reject();
}

void ViewEmployeeDialog::init()
{
    ui->displayCombo->insertItem(0, "Payroll");
    ui->displayCombo->insertItem(1, "Daily Record");
}

void ViewEmployeeDialog::loadBtnClicked()
{
    DirectoryDialog directoryDialog;
    connect(&directoryDialog, SIGNAL(output(QString)), this, SLOT(getLoadDirectory(QString)));
    directoryDialog.exec();
}

void ViewEmployeeDialog::exportBtnClicked()
{
    DirectoryDialog directoryDialog;
    connect(&directoryDialog, SIGNAL(output(QString)), this, SLOT(getExportDirectory(QString)));
    directoryDialog.exec();
}

void ViewEmployeeDialog::getLoadDirectory(QString dir)
{
    CvsFileReader fileReader;
    fileReader.readToDailyRecordCatalog(employee->getDailyRecordCatalog(), dir);
    displayDailyRecord();
}

void ViewEmployeeDialog::getExportDirectory(QString dir)
{

}



#include "viewemployeedialog.h"
#include "ui_viewemployeedialog.h"
#include "directorydialog.h"
#include "cvsfilereader.h"
#include "cvsfilewriter.h"

ViewEmployeeDialog::ViewEmployeeDialog(QWidget *parent, Employee *e) :
    QDialog(parent),
    ui(new Ui::ViewEmployeeDialog),
    holidaySet(new QSet<QDate>()),
    employee(e)
{

    ui->setupUi(this);

    ui->empIdLabel->setText(QString::number(employee->getPerson()->getId()));
    ui->empNameLabel->setText(employee->getPerson()->getFirstName() + " " +
                              employee->getPerson()->getLastName());
    ui->payPeriodLabel->setText(employee->getPayPeriod());
    ui->roleLabel->setText(employee->getPerson()->getRole());

    ui->bonusSpin->setMinimum(1.0);

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
    connect(ui->payBtn, SIGNAL(clicked(bool)), this, SLOT(makePayment()));

    init();
}

ViewEmployeeDialog::~ViewEmployeeDialog()
{
    delete ui;
    delete holidaySet;
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
    QString salaryPerUnit = ui->salaryPerUnitTxt->text();
    QTime startTime = ui->startTimeEdit->time();
    QTime endTime = ui->endTimeEdit->time();
    double bonus = ui->bonusSpin->value();

    DailyRecordCatalog *dailyRecordCatalog = employee->getDailyRecordCatalog();
    DailyRecord* dailyRecord = dailyRecordCatalog->createDailyRecord();
    dailyRecord->setDate(startDate);
    dailyRecord->setStartTime(startTime);
    dailyRecord->setEndTime(endTime);
    dailyRecord->setBonus(bonus);
    dailyRecord->setIsPay(false);

    displayDailyRecord();
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
        double bonus = dailyRecord->getBonus();
        double totalSalary = hours * salaryPerUnit * bonus;

        QTableWidgetItem *id = new QTableWidgetItem(QString::number(dailyRecord->getId()));
        QTableWidgetItem *date = new QTableWidgetItem(dailyRecord->getDate().toString());
        QTableWidgetItem *startTime = new QTableWidgetItem(dailyRecord->getStartTime().toString());
        QTableWidgetItem *endTime = new QTableWidgetItem(dailyRecord->getEndTime().toString());
        QTableWidgetItem *workUnits = new QTableWidgetItem(QString::number(hours));
        QTableWidgetItem *total = new QTableWidgetItem(QString::number(totalSalary));
        QTableWidgetItem *isPay = new QTableWidgetItem(dailyRecord->getIsPay() ? "Yes" : "No");

        ui->empPayrollTable->setItem(i, 0, id);
        ui->empPayrollTable->setItem(i, 1, date);
        ui->empPayrollTable->setItem(i, 2, startTime);
        ui->empPayrollTable->setItem(i, 3, endTime);
        ui->empPayrollTable->setItem(i, 4, workUnits);
        ui->empPayrollTable->setItem(i, 5, total);
        ui->empPayrollTable->setItem(i, 6, isPay);

    }

    ui->empPayrollTable->setHorizontalHeaderLabels(QStringList()
                                                 << "ID"
                                                 << "Date"
                                                 << "Start Time"
                                                 << "End Time"
                                                 << "Work Units"
                                                 << "Total Salary"
                                                 << "Is Pay");


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
    ui->payBtn->setEnabled(isEnabled);
}

void ViewEmployeeDialog::makePayment()
{
    PayrollDirectory *payrollDirectory = employee->getPayrollDirectory();
    QItemSelectionModel *selectModel = ui->empPayrollTable->selectionModel();

    vector<DailyRecord*>* payRecords = new vector<DailyRecord*>();

    if (selectModel->hasSelection()) {
        QModelIndexList indexList = selectModel->selectedRows();

        for (int i = 0; i < indexList.size(); i++) {
            int index = indexList.at(i).row();
            QTableWidgetItem *item = ui->empPayrollTable->item(index, 0);
            int id = item->text().toInt();

            DailyRecordCatalog *dailyRecordCatalog = employee->getDailyRecordCatalog();
            DailyRecord *dailyRecord = dailyRecordCatalog->getDailyRecordById(id);

            payRecords->push_back(dailyRecord);

            dailyRecord->setIsPay(true);
        }
        generatePayroll(payRecords);
        displayPayrolls();
    }
}

void ViewEmployeeDialog::generatePayroll(vector<DailyRecord*>* records)
{
    DailyRecord* end = findNewestRecord(records);
    DailyRecord* start = findOldestRecord(records);
    double workUnits = getWorkUnitsByDailyRecords(records);

    PayrollDirectory* payrollDirectory = employee->getPayrollDirectory();
    Payroll *payroll = payrollDirectory->createPayroll();
    payroll->setStartDate(start->getDate());
    payroll->setEndDate(end->getDate());
    payroll->setSalaryPerUnit(employee->getSalaryPerUnit());
    payroll->setWorkUnits(workUnits);

}

double ViewEmployeeDialog::getWorkUnitsByDailyRecords(vector<DailyRecord*>* records)
{
    double units = 0;
    for (int i = 0; i < records->size(); i++) {
        DailyRecord *dailyRecord = records->at(i);
        units += dailyRecord->getWorkHours() * dailyRecord->getBonus();
    }
    return units;
}

DailyRecord* ViewEmployeeDialog::findNewestRecord(vector<DailyRecord *> *records)
{
    DailyRecord* newest = records->at(0);
    for (int i = 1; i < records->size(); i++) {
        DailyRecord* record = records->at(i);
        QDate recordDate = record->getDate();
        QDate newestDate = newest->getDate();
        if (recordDate.operator >(newestDate)) {
            newest = record;
        }
    }
    return newest;
}

DailyRecord* ViewEmployeeDialog::findOldestRecord(vector<DailyRecord *> *records)
{
    DailyRecord* oldest = records->at(0);
    for (int i = 1; i < records->size(); i++) {
        DailyRecord* record = records->at(i);
        QDate recordDate = record->getDate();
        QDate oldestDate = oldest->getDate();
        if (recordDate.operator <(oldestDate)) {
            oldest = record;
        }
    }
    return oldest;
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

    if (isHoliday(&startDate)) {
        ui->bonusSpin->setMinimum(1.5);
        ui->bonusSpin->setValue(1.5);
    } else {
        ui->bonusSpin->setMinimum(1);
        ui->bonusSpin->setValue(1);
    }
}

bool ViewEmployeeDialog::isHoliday(QDate* date)
{
    int day = date->dayOfWeek();
    if (day == 6 || day == 7 || holidaySet->contains(*date)) {
        return true;
    }
    return false;
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
    PayrollDirectory *payrollDirectory = employee->getPayrollDirectory();
    CvsFileWriter fileWriter;
    fileWriter.writePayrollsToFile(payrollDirectory, dir);
}

void ViewEmployeeDialog::back()
{
    QDialog::reject();
}

void ViewEmployeeDialog::init()
{
    ui->displayCombo->insertItem(0, "Payroll");
    ui->displayCombo->insertItem(1, "Daily Record");

    holidaySet->insert(QDate(2015, 12, 24));
    holidaySet->insert(QDate(2015, 12, 25));
    holidaySet->insert(QDate(2015, 12, 26));
    holidaySet->insert(QDate(2016, 1, 1));
    holidaySet->insert(QDate(2016, 6, 4));

}


#include "addempdialog.h"
#include "ui_addempdialog.h"
#include "personfactory.h"
#include "adminwindow.h"
#include <iostream>

AddEmpDialog::AddEmpDialog(QWidget *parent, EmployeeDirectory *ed) :
    QDialog(parent),
    ui(new Ui::AddEmpDialog),
    employeeDirectory(ed)
{
    ui->setupUi(this);

    init();

    connect(ui->createBtn, SIGNAL(clicked(bool)), this, SLOT(createBtnClicked()));
    connect(ui->backBtn, SIGNAL(clicked(bool)), this, SLOT(backBtnClicked()));
}

AddEmpDialog::~AddEmpDialog()
{
    delete ui;
}

void AddEmpDialog::createBtnClicked()
{
    QString fname = ui->fnameTxt->text();
    QString lname = ui->lnameTxt->text();
    int age = ui->ageTxt->text().toInt();
    QString phone = ui->phoneTxt->text();
    QString department = ui->departmentTxt->text();
    double salaryPerUnit = ui->salaryPerUnitTxt->text().toDouble();
    QString role = ui->roleCombo->currentText();
    QString payPeriod = ui->payPeriodCombo->currentText();


    PersonFactory personFactory;
    Person *person = personFactory.getPerson(role);
    person->setFirstName(fname);
    person->setLastName(lname);
    person->setAge(age);
    person->setPhoneNum(phone);


    Employee *employee = employeeDirectory->createEmployee();
    employee->setPerson(person);
    employee->setDepartment(department);
    employee->setPayPeriod(payPeriod);
    employee->setSalaryPerUnit(salaryPerUnit);
    employee->setPayPeriod(payPeriod);

    QDialog::accept();
}

void AddEmpDialog::backBtnClicked()
{
    QDialog::accept();
}

void AddEmpDialog::init()
{
    ui->roleCombo->insertItem(0, "Student");
    ui->roleCombo->insertItem(1, "Teacher");
    ui->roleCombo->insertItem(2, "Executive");
    ui->roleCombo->insertItem(3, "Staff");
    ui->roleCombo->insertItem(4, "Volunteer");

    ui->payPeriodCombo->insertItem(0, "Day");
    ui->payPeriodCombo->insertItem(1, "Week");
    ui->payPeriodCombo->insertItem(2, "BiWeek");
    ui->payPeriodCombo->insertItem(3, "Month");
    ui->payPeriodCombo->insertItem(4, "Year");
}

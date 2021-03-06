#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    adminUsername = "admin";
    adminPassword = "admin";
    employeeDirectory = new EmployeeDirectory();

    connect(ui->loginBtn, SIGNAL(clicked(bool)), this, SLOT(loginBtnClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loginBtnClicked()
{
    QString username = ui->usernameTxt->text();
    QString password = ui->passwordTxt->text();
    bool isValid = validate(username, password);
    if (isValid) {
        displayAdminWorkWindow();
    } else {

    }
}

bool MainWindow::validate(QString username, QString password)
{
    bool isEqual = (username == adminUsername) &&
                   (password == adminPassword);
    return isEqual;
}

void MainWindow::displayAdminWorkWindow()
{
    AdminWindow adminWindow;
    adminWindow.show();
}

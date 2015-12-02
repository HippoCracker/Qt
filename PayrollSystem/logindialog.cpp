#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->errorLabel->hide();

    adminUsername = "admin";
    adminPassword = "admin";

    connect(ui->loginBtn, SIGNAL(clicked(bool)), this, SLOT(loginBtnClicked()));


}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::loginBtnClicked()
{
    QString username = ui->usernameTxt->text();
    QString password = ui->passwordTxt->text();
    bool isValid = validate(username, password);
    if (isValid) {
        QDialog::accept();
    } else {
        ui->errorLabel->show();
    }
}

bool LoginDialog::validate(QString username, QString password)
{
    bool isEqual = (username == adminUsername) &&
                   (password == adminPassword);
    return isEqual;
}

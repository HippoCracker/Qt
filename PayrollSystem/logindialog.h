#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

public slots:
    void loginBtnClicked();

private:
    Ui::LoginDialog *ui;
    QString adminUsername;
    QString adminPassword;

    bool validate(QString username, QString password);
    void displayAdminWorkWindow();
};

#endif // LOGINDIALOG_H

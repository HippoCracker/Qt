#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "employeedirectory.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void loginBtnClicked();


private:
    Ui::MainWindow *ui;

    EmployeeDirectory *employeeDirectory;
    QString adminUsername;
    QString adminPassword;

    bool validate(QString username, QString password);
    void displayAdminWorkWindow();
};

#endif // MAINWINDOW_H

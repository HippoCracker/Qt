#include <QApplication>
#include "mainwindow.h"
#include "adminwindow.h"
#include "logindialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginDialog loginDialog;
    AdminWindow adminWindow;

    if (loginDialog.exec() == QDialog::Accepted) {
        adminWindow.show();
    }

    return a.exec();
}

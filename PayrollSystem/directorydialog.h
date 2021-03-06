#ifndef DIRECTORYDIALOG_H
#define DIRECTORYDIALOG_H

#include <QDialog>

namespace Ui {
class DirectoryDialog;
}

class DirectoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DirectoryDialog(QWidget *parent = 0);
    ~DirectoryDialog();

    QString getDirectory();

public slots:
    void okBtnClicked();

signals:
    void output(QString);

private:
    Ui::DirectoryDialog *ui;
};

#endif // DIRECTORYDIALOG_H

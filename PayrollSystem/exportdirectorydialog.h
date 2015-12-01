#ifndef EXPORTDIRECTORYDIALOG_H
#define EXPORTDIRECTORYDIALOG_H

#include <QDialog>

namespace Ui {
class ExportDirectoryDialog;
}

class ExportDirectoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExportDirectoryDialog(QWidget *parent = 0);
    ~ExportDirectoryDialog();

private:
    Ui::ExportDirectoryDialog *ui;
};

#endif // EXPORTDIRECTORYDIALOG_H

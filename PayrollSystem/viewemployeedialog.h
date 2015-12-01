#ifndef VIEWEMPLOYEEDIALOG_H
#define VIEWEMPLOYEEDIALOG_H

#include <QDialog>

namespace Ui {
class ViewEmployeeDialog;
}

class ViewEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewEmployeeDialog(QWidget *parent = 0);
    ~ViewEmployeeDialog();

private:
    Ui::ViewEmployeeDialog *ui;
};

#endif // VIEWEMPLOYEEDIALOG_H

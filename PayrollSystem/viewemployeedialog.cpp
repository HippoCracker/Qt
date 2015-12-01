#include "viewemployeedialog.h"
#include "ui_viewemployeedialog.h"

ViewEmployeeDialog::ViewEmployeeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewEmployeeDialog)
{
    ui->setupUi(this);
}

ViewEmployeeDialog::~ViewEmployeeDialog()
{
    delete ui;
}

#include "exportdirectorydialog.h"
#include "ui_exportdirectorydialog.h"

ExportDirectoryDialog::ExportDirectoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExportDirectoryDialog)
{
    ui->setupUi(this);
}

ExportDirectoryDialog::~ExportDirectoryDialog()
{
    delete ui;
}

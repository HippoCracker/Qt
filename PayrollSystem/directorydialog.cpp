#include "directorydialog.h"
#include "ui_directorydialog.h"

DirectoryDialog::DirectoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DirectoryDialog)
{
    ui->setupUi(this);

    connect(ui->okBtn, SIGNAL(clicked(bool)), this, SLOT(okBtnClicked()));
}

DirectoryDialog::~DirectoryDialog()
{
    delete ui;
}

void DirectoryDialog::okBtnClicked()
{
    QString dir = ui->dirTxt->text();
    emit output(dir);
    QDialog::accept();
}

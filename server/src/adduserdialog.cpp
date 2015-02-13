#include "adduserdialog.h"
#include "ui_adduserdialog.h"

AddUserDialog::AddUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddUserDialog)
{
    ui->setupUi(this);
}

AddUserDialog::~AddUserDialog()
{
    delete ui;
}
//----------------------------------------------------------------------

QString AddUserDialog::getClientName()
{
    return ui->leClientName->text();
}
//----------------------------------------------------------------------

QString AddUserDialog::getClientAddress()
{
    return ui->leClientAddress->text();
}
//----------------------------------------------------------------------

int AddUserDialog::getClientPort()
{
    return ui->spClientPort->value();
}

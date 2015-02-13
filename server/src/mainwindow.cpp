#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
//--------------------------------------------------------------------------

MainWindow::~MainWindow()
{
    delete ui;
}
//--------------------------------------------------------------------------

void MainWindow::slotAddClientPbCliced()
{
    AddUserDialog d(this);
    if(d.exec())
    {
        server.addClient(d.getClientName(), d.getClientAddress(), d.getClientPort());

        QMap<QString,ClientAddress>* buf = server.getClientsList();
        ui->teClients->clear();
        foreach (QString client, buf->keys())
        {
            ui->teClients->append(QString("%1 - %2:%3")
                                  .arg(client)
                                  .arg(buf->value(client).addr)
                                  .arg(buf->value(client).port));
        }
    }
    else
    {
        //ui->teClients->setText("CANCEL");
    }
}
//--------------------------------------------------------------------------

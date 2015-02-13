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
        QStandardItemModel *model = new QStandardItemModel(buf->count(), 3, ui->tvClients);
        ui->tvClients->setModel(model);
        ui->teClients->clear();
        int rowCount = 0;
        foreach (QString client, buf->keys())
        {
            QStandardItem* name = new QStandardItem(client);
            QStandardItem* addr = new QStandardItem(buf->value(client).addr);
            QStandardItem* port = new QStandardItem(tr("%1").arg(buf->value(client).port));
            model->setItem(rowCount, 0, name);
            model->setItem(rowCount, 1, addr);
            model->setItem(rowCount, 2, port);
            rowCount++;
        }
    }
    else
    {
        //ui->teClients->setText("CANCEL");
    }
}
//--------------------------------------------------------------------------

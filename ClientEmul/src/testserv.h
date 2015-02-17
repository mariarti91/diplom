#ifndef TESTSERV_H
#define TESTSERV_H

#include <QObject>
#include <QTcpServer>
#include <iostream>

#include "clientsock.h"

class TestServ : public QObject
{
    Q_OBJECT
public:
    explicit TestServ(QObject *parent = 0);
    ~TestServ();

    void initServ(const int &port);

private:
    QTcpServer *srv;
    QMap<QString, ClientSock*> users;
signals:

public slots:
    void newConnection();
    void connectClosed(QString name);
};

#endif // TESTSERV_H

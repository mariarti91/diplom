#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QTcpServer>
#include <QTimerEvent>

#include "clientsock.h"

struct ClientAddress
{
    ClientAddress();
    ClientAddress(const QString&, const int&);
    ~ClientAddress();
    QString addr;
    int port;
};

class MyServer : public QObject
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);
    ~MyServer();

    void addClient(const QString &name, const QString &addr, const int &port);
    QMap<QString, ClientAddress>* getClientsList();

private:
    QMap<QString, ClientAddress> clients;
    void timerEvent(QTimerEvent* event);

signals:

public slots:

};

#endif // MYSERVER_H

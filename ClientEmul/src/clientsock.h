#ifndef CLIENTSOCK_H
#define CLIENTSOCK_H

#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <QTimer>
#include <QTimerEvent>
#include <iostream>

#include "globaldefines.h"

class ClientSock : public QObject
{
    Q_OBJECT
public:
    explicit ClientSock(QObject *parent = 0);
    explicit ClientSock(QString addr, int port, QObject *parent = 0);
    explicit ClientSock(QTcpSocket *sock, QObject *parent = 0);
    ~ClientSock();
    void initSc(const QString & addr, const int & port);
    void setName(const QString & name);
    QString getName();
    void sendData(QByteArray data);
    void timerEvent(QTimerEvent *event);
private:
    QTcpSocket * sc;
    QString m_qsScName;
signals:
    void scDisconnect(QString);
public slots:
    QByteArray getData();
};

#endif // CLIENTSOCK_H

#include "clientsock.h"

ClientSock::ClientSock(QObject *parent) :
    QObject(parent)
{
    sc = new QTcpSocket(this);
}
//--------------------------------------------------------------------

ClientSock::ClientSock(QString addr, int port, QObject *parent) :
    QObject(parent)
{
    sc = new QTcpSocket(this);
    initSc(addr, port);
}
//--------------------------------------------------------------------

ClientSock::ClientSock(QTcpSocket *sock, QObject *parent) :
    QObject(parent)
{
    sc = sock;
    this->setName(QString("%1").arg(sock->peerPort()));
    connect(sc, SIGNAL(readyRead()), this, SLOT(getData()));
    startTimer(5000);
}

//--------------------------------------------------------------------

ClientSock::~ClientSock()
{
    delete sc;
}
//--------------------------------------------------------------------

void ClientSock::initSc(const QString &addr, const int &port)
{
    sc->connectToHost(addr, port);
    connect(sc, SIGNAL(readyRead()), this, SLOT(getData()));
}
//--------------------------------------------------------------------

QByteArray ClientSock::getData()
{
    QByteArray buf(sc->readAll());
    std::cout << m_qsScName.toStdString() << ": " << QString(buf).toStdString() << std::endl;
    quint16 uspdId = 0x0003;
    QString uspdData("it's USPD status");
    QString uuData("it's UU data");
    QByteArray responce;
    QDataStream res(&responce, QIODevice::WriteOnly);
    //responce.append(uspdId);
    //responce.append(uspdData.length());
    //responce.append(uspdData);
    //responce.append(uuData.length());
    //responce.append(uuData);
    res << uspdId << uspdData.toUtf8() << uuData.toUtf8();
    sendData(responce);
    this->deleteLater();
    return buf;
}
//--------------------------------------------------------------------

void ClientSock::setName(const QString &name)
{
    m_qsScName = name;
}
//--------------------------------------------------------------------

void ClientSock::sendData(QByteArray data)
{
    if(sc->state() == QAbstractSocket::ConnectedState)
    {
        sc->write(data);
        sc->waitForBytesWritten();
    }
}
//--------------------------------------------------------------------

void ClientSock::timerEvent(QTimerEvent *event)
{
    if(sc->state() == QAbstractSocket::UnconnectedState)
    {
        killTimer(event->timerId());
        std::cout << m_qsScName.toStdString() << " status: CLOSED" << std::endl;
        emit scDisconnect(m_qsScName);
    }
    else
    {
        //std::cout << m_qsScName.toStdString() << " status: OK" << std::endl;
    }
}
//--------------------------------------------------------------------

QString ClientSock::getName()
{
    return m_qsScName;
}
//--------------------------------------------------------------------

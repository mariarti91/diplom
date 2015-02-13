#include "myserver.h"

ClientAddress::ClientAddress(){}
//----------------------------------------------------------------------------

ClientAddress::ClientAddress(const QString & a, const int & p)
{
    this->addr = a;
    this->port = p;
}
//----------------------------------------------------------------------------

ClientAddress::~ClientAddress(){}
//============================================================================

MyServer::MyServer(QObject *parent) :
    QObject(parent)
{
}
//----------------------------------------------------------------------------

MyServer::~MyServer(){}
//----------------------------------------------------------------------------

void MyServer::addClient(const QString &name,
                         const QString &addr,
                         const int &port)
{
    clients.insert(name, ClientAddress(addr, port));
}
//----------------------------------------------------------------------------

QMap<QString, ClientAddress>* MyServer::getClientsList()
{
    return &clients;
}
//----------------------------------------------------------------------------

void MyServer::timerEvent(QTimerEvent *event)
{

}

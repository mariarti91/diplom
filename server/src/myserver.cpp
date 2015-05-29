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
    startTimer(10000);
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
    std::cout << "event!" << std::endl;
    foreach (QString name, this->clients.keys())
    {
        //ClientSock sc(clients.value(name).addr, clients.value(name).port);
        //sc.setName(name);
        //sc.sendData("test");
        ClientSock* sc = new ClientSock(clients.value(name).addr, clients.value(name).port);
        sc->setName(name);
        sc->sendData("get_request");
    }
}
//----------------------------------------------------------------------------

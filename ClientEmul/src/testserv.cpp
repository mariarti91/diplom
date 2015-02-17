#include "testserv.h"

TestServ::TestServ(QObject *parent) :
    QObject(parent)
{
    srv = new QTcpServer(this);
    connect(srv, SIGNAL(newConnection()), this, SLOT(newConnection()));
}
//----------------------------------------------------------

TestServ::~TestServ()
{
    delete srv;
}
//----------------------------------------------------------

void TestServ::initServ(const int &port)
{
    if(srv->listen(QHostAddress::Any, port))
    {
        std::cout << "server up!" << std::endl;
    }
    else
    {
        std::cout << "ooooooooooops!!!!!" << std::endl;
    }
}
//----------------------------------------------------------

void TestServ::newConnection()
{
    std::cout << "get connection =)" << std::endl;
    //users.push_front(srv->nextPendingConnection());
    ClientSock * sock = new ClientSock(srv->nextPendingConnection());
    connect(sock, SIGNAL(scDisconnect(QString)), this, SLOT(connectClosed(QString)));
    users.insert(sock->getName(), sock);
}
//----------------------------------------------------------

void TestServ::connectClosed(QString name)
{
    delete users.value(name);
    users.remove(name);
}

#include <QCoreApplication>
#include <iostream>

#include "clientsock.h"
#include "testserv.h"

int main(int argc, char** argv)
{
	QCoreApplication app(argc, argv);
    TestServ serv;
    serv.initServ(QString(argv[1]).toInt());
	return app.exec();
}

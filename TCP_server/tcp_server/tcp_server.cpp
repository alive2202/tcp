#include "tcp_server.h"

tcp_server::tcp_server()
{

}

void tcp_server::startServer()
{
  if(this->listen(QHostAddress::Any, 2222))
    {
     qDebug("Started listen to network");
    }
  else
    {
     qDebug("Cant listen to network");
    }
}

void tcp_server::incomingConnection(int socketDescriptor)
{
 socket = new QTcpSocket(this);
 socket->setSocketDescriptor(socketDescriptor);

 connect(socket, SIGNAL(readyRead()), this, SLOT(readSocket()));
 connect(socket, SIGNAL(disconnected()), this, SLOT(justDisconnect()));

 qDebug("New connection is here %d!!!!",socketDescriptor );

}


void tcp_server::readSocket()
{
    if(socket->waitForConnected(500))
    {
    socket->waitForReadyRead(500);
        Data = socket->readAll();

 if(Data!=0) {
     qDebug() << "Server got Data = " << Data << "\n";
     socket->write("Server received some data");
 }
 else  qDebug() << "Data is null \n";

}

}

void tcp_server::justDisconnect()
{
 socket->deleteLater();
 qDebug() << "Connection is lost \n";
}





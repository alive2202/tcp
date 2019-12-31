#include "tcp_server.h"
#include "QFile"
#include "QDir"
tcp_server::tcp_server()
{
 QDir d;
 QFile file;
 QString FileName = "D:\\football.json";
 file.setFileName(FileName);
 if(file.open(QIODevice::ReadOnly|QFile::Text))
   {
     FileData = file.readAll();
   }
 else
     qDebug("Cant open file %s", FileName.toLocal8Bit().data());

 file.close();
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
     //socket->write("Server received some data");
     //QString str("{\"type\":\"connect\",\"status\":\"yes\"}");
     //socket->write("{\"type\":\"connect\",\"status\":\"yes\"}");
     //cstr.toLatin1());

     doc = QJsonDocument::fromJson(Data,&err);
     if(err.errorString()=="no error occurred")
     {
      if( (doc.object().value("type").toString()=="select") &&
          (doc.object().value("data").toString()=="players")   )
        {
         QByteArray send = "{\"type\":\"resultSelect\",\"result\":"+FileData+"}";
         socket->write(send);
         socket->waitForBytesWritten(500);
        }
      else if( (doc.object().value("type").toString()=="select") &&
          (doc.object().value("data").toString()=="fc name")   )
        {
         QByteArray send = "{\"type\":\"resultSelect\",\"result\":"+FileData+"}";
         socket->write(send);
         socket->waitForBytesWritten(500);
        }



     }

 }
 else  qDebug() << "Data is null \n";

}

}

void tcp_server::justDisconnect()
{
 socket->deleteLater();
 qDebug() << "Connection is lost \n";
}





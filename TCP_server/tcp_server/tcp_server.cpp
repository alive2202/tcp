#include "tcp_server.h"
#include "QFile"
#include "QDir"
tcp_server::tcp_server()
{
 db = QSqlDatabase::addDatabase("QSQLITE");
 db.setDatabaseName("C:\\sqlite\\football.db");

 if(db.open())
 {
  qDebug("DATA BASE was opened");
 }
 else qDebug("DATA BASE was NOT opened");

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
     //qDebug() << "Server got Data = " << Data << "\n";

     doc = QJsonDocument::fromJson(Data,&err);
     if(err.errorString()=="no error occurred")
     {
      if( (doc.object().value("type").toString()=="select") &&
          (doc.object().value("data").toString()=="players")   )
        {
         //QByteArray send = "{\"type\":\"resultSelect\",\"result\":"+FileData+"}";

         if(db.isOpen())
         {
             QByteArray send = "{\"type\":\"resultSelect\",\"result\":[";
             QSqlQuery *query = new QSqlQuery(db);
             if(query->exec("SELECT Player FROM T_Players"))
             {
                while(query->next())
                {
                 send.append("{\"name\":\""+query->value(0).toString()+"\"},");
                }

                send.remove(send.length()-1,1);
                send.append("]}");

                qDebug() << send << "\n";

                socket->write(send);
                socket->waitForBytesWritten(500);
             }
             else qDebug() << "Cant read palyers from DB \n";


         }
        }
      else if( (doc.object().value("type").toString()=="select") &&
          (doc.object().value("data").toString()=="fc name")   )
        {
          if(db.isOpen())
          {
              QByteArray send = "{\"type\":\"resultSelect2\",\"result\":[";
              QSqlQuery *query = new QSqlQuery(db);
              if(query->exec("SELECT FC_name FROM T_Players"))
              {
                 QSet <QString> fc_set;

                 while(query->next())
                 {
                  if(!fc_set.contains(query->value(0).toString()))
                  {
                   send.append("{\"FC name\":\""+query->value(0).toString()+"\"},");
                   fc_set.insert(query->value(0).toString());
                  }
                 }

                 fc_set.clear();

                 send.remove(send.length()-1,1);
                 send.append("]}");

                 qDebug() << send << "\n";

                 socket->write(send);
                 socket->waitForBytesWritten(500);
              }
              else qDebug() << "Cant read fc names from DB \n";

        }
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





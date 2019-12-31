#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>

#include <QSqlDatabase>
#include <QSqlQuery>

#include <QSet>



class tcp_server : public QTcpServer
{
 Q_OBJECT

public:
    tcp_server();

    QTcpSocket *socket;
    QByteArray Data;
    QByteArray FileData;


    QJsonDocument doc;
    QJsonParseError err;

    QSqlDatabase db;

public slots:
    void startServer();
    void readSocket();
    void incomingConnection(int socketDescriptor);
    void justDisconnect();


};

#endif // TCP_SERVER_H

#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>


class tcp_server : public QTcpServer
{
 Q_OBJECT

public:
    tcp_server();

    QTcpSocket *socket;
    QByteArray Data;

public slots:
    void startServer();
    void readSocket();
    void incomingConnection(int socketDescriptor);
    void justDisconnect();


};

#endif // TCP_SERVER_H

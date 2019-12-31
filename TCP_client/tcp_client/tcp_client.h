#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QStandardItem>

namespace Ui {
class tcp_client;
}

class tcp_client : public QMainWindow
{
    Q_OBJECT

public:
    explicit tcp_client(QWidget *parent = 0);
    ~tcp_client();

    QTcpSocket *socket;
    QByteArray Data;

        QJsonDocument doc;
        QJsonParseError err;

public slots:
    void readSocket();
    void justDisconnect();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::tcp_client *ui;
};

#endif // TCP_CLIENT_H

#include "tcp_client.h"
#include "ui_tcp_client.h"

tcp_client::tcp_client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tcp_client)
{
    ui->setupUi(this);

    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readSocket()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(justDisconnect()));

}

tcp_client::~tcp_client()
{
    delete ui;
}

void tcp_client::readSocket()
{
 if(socket->waitForConnected(500))
 {
 socket->waitForReadyRead(500);
     Data = socket->readAll();


  if(Data!=0) {
     qDebug("Client got Data ");
     //socket->write("Client received some data");
  }
  else  qDebug("Data is null");
 }


}

void tcp_client::justDisconnect()
{
     qDebug() << "Connection is lost \n";
 socket->deleteLater();

}


void tcp_client::on_pushButton_clicked()
{
 socket->connectToHost("127.0.0.1", 2222);
 qDebug("Connected to server");
 ui->label->setText("Connected to server");
}

void tcp_client::on_pushButton_2_clicked()
{
 static int count=0;
 socket->write(QByteArray::number(count++, 10));
}

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
     //qDebug("Client got Data ");
     //socket->write("Client received some data");
      qDebug() << Data << "\n";

      doc = QJsonDocument::fromJson(Data, &err);

      //if(err.errorString().toInt()==QJsonParseError::NoError)
      if(err.errorString()=="no error occurred")
      {
          if( (doc.object().value("type").toString()=="connect")  &&
              (doc.object().value("status").toString()=="yes") )
          {
           QMessageBox::information(this,"JSON","get good json data");
          }
          else if( (doc.object().value("type").toString()=="resultSelect"))
                   //&& (doc.object().value("result").toString()=="yes") )
          {
           QStandardItemModel *model = new QStandardItemModel();                     
           model->setHorizontalHeaderLabels(QStringList()<<"names");
           QJsonArray arr = doc.object().value("result").toArray();

           qDebug("loop player names  =%d", arr.count());

           for(int i=0; i<arr.count();i++)
           {
            QStandardItem *col = new QStandardItem(arr[i].toObject().value("name").toString());
            model->appendRow(col);

           }

           ui->tableView->setModel(model);
          }
          else if( (doc.object().value("type").toString()=="resultSelect2"))
                   //&& (doc.object().value("result").toString()=="yes") )
          {
           QStandardItemModel *model = new QStandardItemModel();
           model->setHorizontalHeaderLabels(QStringList()<<"FC names");
           QJsonArray arr = doc.object().value("result").toArray();

           qDebug("loop FC names  =%d", arr.count());

           for(int i=0; i<arr.count();i++)
           {
            QStandardItem *col = new QStandardItem(arr[i].toObject().value("FC name").toString());
            model->appendRow(col);

           }

           ui->tableView->setModel(model);
          }
          else QMessageBox::information(this,"JSON","get bad json data");
      }
      else
          QMessageBox::information(this,"JSON","errors with format json "+err.errorString());

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

void tcp_client::on_pushButton_3_clicked()
{
    if(socket->isOpen())
    {
     QString str("{\"type\":\"select\",\"data\":\"fc name\"}");
     socket->write(str.toLatin1());
    }
}

void tcp_client::on_pushButton_4_clicked()
{
    if(socket->isOpen())
    {
     QString str("{\"type\":\"select\",\"data\":\"players\"}");
     socket->write(str.toLatin1());
    }
}

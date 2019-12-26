#include <QCoreApplication>
#include <iostream>

#include "tcp_server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

   // std::cout << "Please, enter the port number :";
   // unsigned int port = 2222;
   // std::cin >> port ;
   // std::cout << "You have entered the port number  :" << port << std::endl;


    tcp_server srv;
    srv.startServer();

    return a.exec();
}

/********************************************************************************
** Form generated from reading UI file 'tcp_client.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCP_CLIENT_H
#define UI_TCP_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tcp_client
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *tcp_client)
    {
        if (tcp_client->objectName().isEmpty())
            tcp_client->setObjectName(QStringLiteral("tcp_client"));
        tcp_client->resize(598, 461);
        centralWidget = new QWidget(tcp_client);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 20, 211, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 50, 191, 16));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 100, 211, 23));
        tcp_client->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(tcp_client);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 598, 21));
        tcp_client->setMenuBar(menuBar);
        mainToolBar = new QToolBar(tcp_client);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        tcp_client->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(tcp_client);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        tcp_client->setStatusBar(statusBar);

        retranslateUi(tcp_client);

        QMetaObject::connectSlotsByName(tcp_client);
    } // setupUi

    void retranslateUi(QMainWindow *tcp_client)
    {
        tcp_client->setWindowTitle(QApplication::translate("tcp_client", "tcp_client", 0));
        pushButton->setText(QApplication::translate("tcp_client", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265", 0));
        label->setText(QApplication::translate("tcp_client", "TextLabel", 0));
        pushButton_2->setText(QApplication::translate("tcp_client", "\320\237\320\265\321\200\320\265\320\264\320\260\321\202\321\214 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", 0));
    } // retranslateUi

};

namespace Ui {
    class tcp_client: public Ui_tcp_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCP_CLIENT_H

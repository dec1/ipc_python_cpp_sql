#pragma once

class MyStore;

class QTcpServer;
class QTcpSocket;

#include <QObject>

//-------------------------------------------------------
class MyNet : public QObject
{
     Q_OBJECT

public:

    MyNet(int port = 8080, MyStore* Store=nullptr);
    ~MyNet();
    void onReceived(QTcpSocket * Conn);
private slots:
    void slotConnected();

private:
    QString parseMesg(QString Mesg);

    QTcpServer * server = nullptr;
    MyStore  * _Store  = nullptr;

    int _port = 8080;
};
//-------------------------------------------------------

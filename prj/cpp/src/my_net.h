#pragma once

class MyStore;

class QTcpServer;
class QTcpSocket;

#include <QObject>

//-------------------------------------------------------
// Enables ipc
//      - listens for tcp connections
//      - parses any messages it receives, executes the encoded instruction on the DataStore (eg MyStoreDb)
//      - sends reply (MyParseResult) to client
//-------------------------------------------------------
class MyNet : public QObject
{
     Q_OBJECT

public:
    MyNet(int port = 8080, MyStore* store=nullptr);
    void onReceived(QTcpSocket * conn);

private slots:
    void slotConnected();

private:
    QString parseMesg(QString mesg);

    QTcpServer * _server = nullptr;
    MyStore  * _store  = nullptr;

    int _port = 8080;
};
//-------------------------------------------------------

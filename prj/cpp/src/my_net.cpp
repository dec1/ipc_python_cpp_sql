#include "my_net.h"
#include "my_store.h"
#include "my_parser.h"
#include "my_parse_result.h"

#include <QString>
#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkInterface>
#include <iostream>


MyNet::MyNet(int port, MyStore * Store)
    : QObject(), _port(port), _Store(Store)
{

    server = new QTcpServer(this);


    if (!server->listen(QHostAddress::Any, port))
        qDebug()<< tr ("Unable to start the server: %1.").arg(server->errorString());

    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }

    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

    connect(server, &QTcpServer::newConnection, this, &MyNet::slotConnected);

    qDebug()<< QString("MyNet (c++) - server is running on IP: %1, port: %2. Clients can connect now.")
               .arg(ipAddress).arg(server->serverPort());
}
//--------------------------------------
void MyNet::onReceived(QTcpSocket * Conn)
{
    QString Mesg  = Conn->readAll();
    qDebug() << "MyNet (c++), received" << Mesg ;

    QString Reply = parseMesg(Mesg);
    Conn->write(Reply.toUtf8());

    qDebug()<< "MyNet::onReceived() wrote reply: "<<Reply.toUtf8();
}
//--------------------------------------
QString MyNet::parseMesg(QString Mesg)
{
        if(!_Store)
        {
            qDebug("Parser requitres backing data store before messages can be parsed");
            return QString();
        }

        MyParser Parser(_Store);
        MyParseResult Res = Parser.from_String(Mesg);
        QString Ret;
        Ret = Res.Value;

        return Ret;
}
//--------------------------------------
void MyNet::slotConnected()
{
    QTcpSocket *clientConnection = server->nextPendingConnection();
    QObject::connect(
        clientConnection, &QTcpSocket::readyRead, this,
        [this, clientConnection]()
        {
            this->onReceived(clientConnection);
        }
    );

    connect(clientConnection, &QAbstractSocket::disconnected,
            clientConnection, &QObject::deleteLater);
}
//----------------------------------
MyNet::~MyNet()
{

}

#include "my_net.h"
#include "my_store_db.h"

#include <QCoreApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QCommandLineParser parser;

    QCommandLineOption port_opt({"p","port"}, "port tcp server should listen on (pass eg:  '-p 8082' or '--port 8082'", "port to listens", "8080");
    parser.addOption(port_opt);
    parser.parse(QCoreApplication::arguments());
    QString val_p = parser.value("port");
    int port = val_p.toInt();



    MyStoreDb Store;
    MyNet Net(port, &Store);

    cout << "main c++ - listening on port: "  << port <<endl ;
    auto ret = a.exec();

    return ret;


}

#include "my_store_db.h"


#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QtDebug>
#include <QString>



//-------------------------------------------------------
QString  MyStoreDb::conn_name(){ return "my_conn";}
QString  db_name(){ return "my_db";}
QString  table_name(){ return "my_tab";}
//-------------------------------------------------------
//-------------------------------------------------------

QSqlDatabase MyStoreDb::open()
{
    auto want_remote = false;

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", conn_name());
    if(want_remote)
    {

        db.setHostName("172.17.0.2");
        db.setPort(3306);
    }
    else
    {
         db.setHostName("localhost");

    }

     db.setDatabaseName(db_name());
     db.setUserName("root");
     db.setPassword("root");


     bool ok = db.open();
     if(!ok)
         qDebug() << "Problem opening QSqlDatabase " <<conn_name();

     // create table if necessary
     QSqlQuery qry(db);
     qry.prepare(QString("create table iF NOT EXISTS %1 (id INT NOT NULL , my_name VARCHAR(100),  PRIMARY KEY (ID) );").arg(table_name()));
     if (!qry.exec())
       qDebug() << qry.lastError();


     return db;
}

//-------------------------------------------------------
void MyStoreDb::close()
{
    QSqlDatabase::removeDatabase(conn_name());
}
//-------------------------------------------------------
MyStoreDb::MyStoreDb()
{}
//----------------------------------
MyStoreDb::~MyStoreDb()
{}
//-------------------------------------------------------
bool MyStoreDb::has_name(int id)
{
    return !read_name(id).isEmpty();
}
//-------------------------------------------------------
QString MyStoreDb::read_name(int id)
{
     QString Ret;

     {
        QSqlDatabase db = open();

        QSqlQuery qry(db);

        qry.prepare(QString("select * from %1 where id =%2;").arg(table_name()).arg(id));
        if (!qry.exec())
        qDebug() << qry.lastError();

        //QSqlRecord rec = qry.record();
        //int cols = rec.count();

        qry.first();
        Ret = qry.value("my_name").toString();

     }

     // Both "db" and "query" are destroyed because they are out of scope
     close();

    return Ret;
}
//-------------------------------------------------------
bool MyStoreDb::write_name(int id, QString Name)
{
    {
        QSqlDatabase db = open();

        QSqlQuery qry(db);


        qry.prepare(QString("replace into %1 (id, my_name) VALUES (%2, '%3');").arg(table_name()).arg(id).arg(Name));
        if (!qry.exec())
          qDebug() << qry.lastError();


        QSqlRecord rec = qry.record();
        //int cols = rec.count();
    }

    // Both "db" and "query" are destroyed because they are out of scope
    close();

    return true;

}







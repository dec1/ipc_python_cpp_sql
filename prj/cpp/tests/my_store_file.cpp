#include "my_store_file.h"


#include <QtDebug>
#include <QString>
#include <QDir>


MyStoreFile::MyStoreFile()
{

    _dirPath = QDir::cleanPath(QDir::homePath() + "/" + "_my_store_file_dir_tmp");

    bool pathOk = QDir().mkpath(_dirPath);

    if(!pathOk)
        qDebug()<< QString("Error: MyStoreFile dir unreadable: %1 ").arg(_dirPath);

}
//-------------------------------------------------------
bool MyStoreFile::has_name(int id)
{
    bool ret = QFile(file_path(id)).exists();
    return ret;
}
//-------------------------------------------------------
QString MyStoreFile::read_name(int id)
{
    return read_file(id).simplified();
}
//-------------------------------------------------------
bool MyStoreFile::write_name(int id, QString name)
{
    return write_file(id, name);
}
//-------------------------------------------------------
QString MyStoreFile::file_path(int id)
{
    return QDir::cleanPath(_dirPath + "/" +  QString::number(id));
}
//-------------------------------------------------------
QString MyStoreFile::read_file(int id)
{
    QFile file(file_path(id));
    bool can_read = file.open(QIODevice::ReadOnly | QIODevice::Text);
    return can_read? file.readAll() :QString("empty");
}
//-------------------------------------------------------
bool MyStoreFile::write_file(int id, QString text)
{
    QFile file(file_path(id));
    if(! file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    out << text;
    return true;
}







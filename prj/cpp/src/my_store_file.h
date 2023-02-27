#pragma once

#include "my_store.h"

#include  <QString>

//-------------------------------------------------------
class MyStoreFile : public MyStore
{

public:
    MyStoreFile();

    virtual bool has_name(int id);
    virtual QString read_name(int id);
    virtual bool write_name(int id, QString name);


protected:
    QString read_file(int id);
    bool write_file(int id, QString text);
    QString file_path(int id);

    QString _dirPath;


//-------------------------------------------------------





};


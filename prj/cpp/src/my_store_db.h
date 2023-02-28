#pragma once

#include "my_store.h"

class QString;
class QSqlDatabase;

//-------------------------------------------------------
// Database backing store
//-------------------------------------------------------
class MyStoreDb : public MyStore
{

public:
    MyStoreDb();
    ~MyStoreDb();

    virtual bool has_name(int id);
    virtual QString read_name(int id);
    virtual bool write_name(int id, QString name);


protected:
    static QSqlDatabase open();
    static void close();

//-------------------------------------------------------





};


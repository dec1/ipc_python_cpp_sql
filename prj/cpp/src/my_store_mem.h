#pragma once

#include "my_store.h"
#include <QMap>

class QString;

//-------------------------------------------------------
class MyStoreMem : public MyStore
{

public:
    virtual bool has_name(int id);
    virtual QString read_name(int id);
    virtual bool write_name(int id, QString Name);

protected:
    QMap<int, QString> id_to_name;
};


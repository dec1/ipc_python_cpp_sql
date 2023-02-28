#pragma once

class QString;

//-------------------------------------------------------
//  Encapsulates the actual backing store used for data
//          read/write and query presence of "name"
//          DataBase, File, InMemory can be instantiated
//-------------------------------------------------------
class MyStore
{

public:
    virtual bool has_name(int id)=0;
    virtual QString read_name(int id)=0;
    virtual bool write_name(int id, QString name)=0;

};
//-------------------------------------------------------





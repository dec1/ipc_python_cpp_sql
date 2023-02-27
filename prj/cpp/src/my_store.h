#pragma once

class QString;

//-------------------------------------------------------
class MyStore
{

public:
    virtual bool has_name(int id)=0;
    virtual QString read_name(int id)=0;
    virtual bool write_name(int id, QString Name)=0;

};
//-------------------------------------------------------





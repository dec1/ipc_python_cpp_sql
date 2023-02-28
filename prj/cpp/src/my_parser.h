#pragma once


class MyParseResult;
class QString;
class MyStore;

//-------------------------------------------------------
// Parses messages send by client to Tcp listner (MyNet)
//      - MyStore
//          dependency injection (inversion of control) for actual data backing store
//          useful in particular for testing (when no production database available)
//-------------------------------------------------------
class MyParser
{

public:
    MyParser(MyStore * store)
        : _store(store){};

    MyParseResult from_String(QString mesg);
protected:
    MyStore  * _store;


};


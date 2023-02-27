#pragma once


class MyParseResult;
class QString;
class MyStore;

//--------------------------
class MyParser
{

public:
    MyParser(MyStore * Store)
        : _Store(Store){};

    MyParseResult from_String(QString Mesg);
protected:
    MyStore  * _Store;


};


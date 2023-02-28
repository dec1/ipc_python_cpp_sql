#include "my_parser.h"
#include "my_parse_result.h"
#include "my_store.h"



#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

#include <QString>
#include <QtDebug>



//-------------------------------------------------------
MyParseResult MyParser::from_String(QString Mesg)
{
    MyParseResult Ret;

    if(!_store)
    {
        Ret.Info.append("Mesg Parse Error: no backing store (db or mem) available for data");
        return Ret;
    }

    QStringList Parts = Mesg.split(",");
    auto cnt = Parts.count();
    if (cnt != 2 && cnt != 3)
    {
        Ret.Info.append("Mesg Parse Error: expecting Mesg with at least 2 (comma separated) parts : "
                   " verb       (read|write) "
                   " id         (int <= 0) "
                   " [value]    (string),   only valid when verb is 'write'"
                   " examples: "
                   "    'read 24' "
                   "    'write 25 john' ");
        return Ret;
    }

    QString Verb = Parts.first().simplified().toLower();

    QString Id = Parts.at(1).simplified();
    bool ok = false;
    int  id = Id.toInt(&ok);
    if( !ok || (id < 0) )
    {
        Ret.Info.append("Mesg Parse Error: expecting non-neg integer after first comma");
        return Ret;
    }


    QString Name = cnt==3? Parts.at(2).simplified() : QString();


    if(Verb == "read")
    {
        if (cnt > 2)
          Ret.Info.append("Mesg Parse Warning: anythin after 'id' in 'read' operation will be ignored:" + Parts.at(2));

        Ret.ok = _store->has_name(id);
        Ret.value = _store->read_name(id);
        Ret.op = MyParseResult::Op::Read;
        return Ret;

    }
    else if(Verb == "write")
    {

        Ret.ok = _store->write_name(id, Name);
        Ret.value = Name;
        Ret.op = MyParseResult::Op::Write;

        return Ret;
    }


    Ret.Info.append("Mesg Parse Error: expecting first word of mesg to be 'read' or 'write' but found: " + Verb);
    return Ret;



}
//---------------------------------------------------









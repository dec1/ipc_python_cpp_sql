#pragma once

#include <QStringList>

//-------------------------------------------------------
// Enscapsulates reply to client
//      - after parsing and (possibly) execution of (read/write) instruction encodedin the message they sent
//      - ok: on success
//      - value (read or echo of that writen)
//-------------------------------------------------------
class MyParseResult
{

public:
   enum class Op { Read, Write, None};
   Op op = Op::None;

   bool ok = false;
   QString value;

   QStringList Info;
};
//-------------------------------------------------------





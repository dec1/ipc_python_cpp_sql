#pragma once

#include <QStringList>

//-------------------------------------------------------
class MyParseResult
{

public:
   enum class Op { Read, Write, None};
   Op op = Op::None;

   bool ok = false;
   QString Value;

   QStringList Info;
};
//-------------------------------------------------------





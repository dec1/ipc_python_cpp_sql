#include "my_tests.h"

#include <QTest>

#include "my_math.h"
#include "my_store_db.h"
#include "my_store_mem.h"
#include "my_store_file.h"
#include "my_parser.h"
#include "my_parse_result.h"

#include <QCoreApplication>
#include <QTest>


//----------------------------
QTEST_MAIN(MyTests)
//----------------------------


//---------------------------
void MyTests::initTestCase()
{
}
//---------------------------
void MyTests::cleanupTestCase()
{

}
//---------------------------------------------
void MyTests::init()
{
    qDebug()<< " tJvTests::init()......";
   // man()->init();
}
//---------------------------------------------
void MyTests::cleanup()
{
    qDebug()<< " tJvTests::cleanup()......";
}
//---------------------------------------------
void MyTests::my_math_add()
{
    QVERIFY2(MyMath::add(1,3) == 4, "expecting 1+3 =4 from MyMath::add");
}
//---------------------------------------------
void MyTests::test_write_read()
{
    // todo ---------
    return;


    int argc = 0;
    char *argv = nullptr;

    QCoreApplication a(argc, &argv);

    MyStoreDb sq;

    sq.write_name(26, "sam");
    QString Before = sq.read_name(26);

    QVERIFY2(Before == "sam", "expecting to read back 'sam' from database");


    sq.write_name(26, "joe");
    QString After = sq.read_name(26);

    QVERIFY2(After == "joe", "expecting to read back 'joe' from database");
}

//---------------------------------------------
void MyTests::testParser(MyParser * Parser)
{
     QVERIFY2(Parser,"testParser expects non-null parser ");

    //  happy paths
    auto Res = Parser->from_String("Write, 15, John");
    QVERIFY2(Res.ok,      "parser write val for id=15 to 'John'");

    Res = Parser->from_String("Read, 15");
    QVERIFY2(Res.ok && (Res.Value == "John"),"parser expect read (back) 'John' for id=15");


    // unhappy paths
    Res = Parser->from_String("Read, -1");
    QVERIFY2(!Res.ok && Res.Value.isEmpty(), "parser expect fail result when read for id=-1");

    Res = Parser->from_String("Bad_op, 15");
    QVERIFY2(!Res.ok && Res.Value.isEmpty(), "parser expect fail result when perform BadOp instead of read/write");
}
//---------------------------------------------
void MyTests::testParserMem()
{
    MyStoreMem Store;
    MyParser Parser(&Store);
    testParser(&Parser);

}
//---------------------------------------------
void MyTests::testParserFile()
{
    MyStoreFile Store;
    MyParser Parser(&Store);
    testParser(&Parser);

}

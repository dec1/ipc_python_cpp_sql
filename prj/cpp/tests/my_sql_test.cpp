
#include "my_sql_test.h"

#include "mysql.h"

#include <QCoreApplication>
#include <QTest>



//-------------------------------------
void MySqlTest::test_write_read()
{
    int argc = 0;
    char *argv = nullptr;

    QCoreApplication a(argc, &argv);

    MySql sq;

    sq.write_name(26, "sam");
    QString Before = sq.read_name(26);

    QVERIFY2(Before == "sam", "expecting to read back 'sam' from database");


    sq.write_name(26, "joe");
    QString After = sq.read_name(26);

    QVERIFY2(After == "joey", "expecting to read back 'joe' from database");
}



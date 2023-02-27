#pragma once

#include <QObject>
class MyParser;
//------------------------------------------------------
class MyTests: public QObject
{
    Q_OBJECT

private slots:

    void init();
    void cleanup() ;

    void initTestCase();
    void cleanupTestCase();

    void my_math_add();
    void test_write_read();

    void testParser(MyParser *Parser);
    void testParserMem();
    void testParserFile();


};
//----------------------------------------------



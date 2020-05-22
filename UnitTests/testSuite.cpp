#include <QObject>
#include <vector>
#include <QtTest>
#include <serializationtest.h>
#include <deposittest.h>

#ifdef QTEST_APPLESS_MAIN
#   undef QTEST_APPLESS_MAIN
#   define QTEST_APPLESS_MAIN(class) \
int main(int argc, char *argv[]) \
{ \
    int status = 0;\
    auto runTest = [&status, argc, argv](QObject* obj) {\
        status |= QTest::qExec(obj, argc, argv);\
    };\
\
    runTest(new SerializationTest());\
    runTest(new DepositTest());\
}
#endif

QTEST_APPLESS_MAIN(SerializationTest)



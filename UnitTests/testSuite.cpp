#include <QObject>
#include <vector>
#include <QtTest>
#include <deposittest.h>
#include <serializationtest.h>
#include <persistencetest.h>

#ifdef QTEST_APPLESS_MAIN
#   undef QTEST_APPLESS_MAIN
#   define QTEST_APPLESS_MAIN(class)

int main(int argc, char *argv[])
{
    int status = 0;
    auto runTest = [&status, argc, argv](QObject* obj) {
        status |= QTest::qExec(obj, argc, argv);
    };

    runTest(new DepositTest());
    runTest(new PersistenceTest());
    runTest(new SerializationTest());
}
#endif

QTEST_APPLESS_MAIN(DepositTest)



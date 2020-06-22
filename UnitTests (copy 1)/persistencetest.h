#ifndef PERSISTENCETEST_H
#define PERSISTENCETEST_H

#include <QObject>
#include <QTest>
#include <filesystem>
#include <deposit.h>
class PersistenceTest: public QObject
{
    Q_OBJECT
public:
    PersistenceTest();

private:
    Deposit deposit{};
    std::vector<Entry*> originalEntries;

private slots:
    void initTestCase();
    void cleanupTestCase();
    void SaveLoadConfig();
    void SaveLoadEntries();
};

#endif // PERSISTENCETEST_H

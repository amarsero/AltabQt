#ifndef PERSISTENCETEST_H
#define PERSISTENCETEST_H

#include <QObject>
#include <QTest>
#include <filesystem>

class PersistenceTest: public QObject
{
    Q_OBJECT
public:
    PersistenceTest();

private:
    std::filesystem::path configPath;
    std::filesystem::path savePath;
private slots:
    void initTestCase();
    void cleanupTestCase();
    void SaveLoadConfig();
    void SaveLoadEntries();
};

#endif // PERSISTENCETEST_H

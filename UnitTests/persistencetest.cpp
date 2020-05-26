#include "persistencetest.h"
#include "persistence.h"
#include <filesystem>

namespace fs = std::filesystem;

PersistenceTest::PersistenceTest()
{

}

void PersistenceTest::initTestCase()
{
    configPath = "/tmp/config";
    savePath = "/tmp/suvieja.sav";
}

void PersistenceTest::cleanupTestCase()
{
    if (fs::exists(configPath))
        fs::remove(configPath);

    if (fs::exists(savePath))
        fs::remove(savePath);
}

void PersistenceTest::SaveLoadConfig()
{
    Deposit deposit{};
    Persistence persistence(&deposit);

    std::string testString{"this a string boi"};
    int testNumber = 42;

    Config config{};
    config.testString = testString;
    config.testNumber = testNumber;

    persistence.SaveConfig(config);
    Config copy = persistence.LoadConfig();

    QCOMPARE(config.testString, testString);
    QCOMPARE(config.testNumber, testNumber);
    QCOMPARE(config.testString, copy.testString);
    QCOMPARE(config.testNumber, copy.testNumber);
    QVERIFY(fs::exists(configPath));

}

void PersistenceTest::SaveLoadEntries()
{

}

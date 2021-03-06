#include "persistencetest.h"
#include "persistence.h"
#include <filesystem>
#include <exception>
#include <shortcutentry.h>

namespace fs = std::filesystem;

PersistenceTest::PersistenceTest()
{

}

void PersistenceTest::initTestCase()
{
    std::shared_ptr<Entry> entry;
    std::vector<std::string> nombres = {
        "hola", "chau"
    };
    for(size_t i = 0; i < nombres.size(); i++)
    {
        entry = std::make_shared<ShortcutEntry>();
        entry->Name = nombres[i];
        entry->RunCount = (1 + i) * 255;
        originalEntries.push_back(entry);
        deposit.entries.push_back(entry);
    }
}

void PersistenceTest::cleanupTestCase()
{
}

void PersistenceTest::SaveLoadConfig()
{
    std::string testString{"this a string boi"};
    int testNumber = 42;

    Config config{};
    config.testString = testString;
    config.testNumber = testNumber;

    Persistence::SaveConfig(config);
    Config copy = Persistence::LoadConfig();

    QCOMPARE(config.testString, testString);
    QCOMPARE(config.testNumber, testNumber);
    QCOMPARE(config.testString, copy.testString);
    QCOMPARE(config.testNumber, copy.testNumber);
}

void PersistenceTest::SaveLoadEntries()
{
	try {
		Persistence::SaveEntries(deposit);
	}  catch (std::exception& e) {
		qDebug("%s", e.what());
	}
    deposit.entries.clear();
	Persistence::LoadEntries(deposit);

    QCOMPARE(deposit.entries.size(), originalEntries.size());

	for(size_t i = 0; i < originalEntries.size(); i++) {
        QCOMPARE(deposit.entries[i]->Name, originalEntries[i]->Name);
        QCOMPARE(deposit.entries[i]->RunCount, originalEntries[i]->RunCount);
	}
}

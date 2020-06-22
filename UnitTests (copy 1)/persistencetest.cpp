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
    Entry* entry;
	for(int i = 0; i < 2; i++)
    {
        entry = new ShortcutEntry();
        entry->Name = std::to_string(i);
        deposit.Entries.push_back(entry);
    }
    originalEntries = deposit.Entries;
}

void PersistenceTest::cleanupTestCase()
{
    for(Entry* entry: originalEntries)
    {
        delete entry;
    }
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
	deposit.Clear();
	Persistence::LoadEntries(deposit);

	QCOMPARE(deposit.Entries.size(), originalEntries.size());

	for(size_t i = 0; i < originalEntries.size(); i++) {
		QCOMPARE(deposit.Entries[i]->Name, originalEntries[i]->Name);
		QCOMPARE(deposit.Entries[i]->RunCount, originalEntries[i]->RunCount);
	}
}

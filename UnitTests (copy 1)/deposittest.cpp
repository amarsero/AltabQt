#include "deposittest.h"
#include "shortcutentry.h"
#include <string>
#include <algorithm>

DepositTest::DepositTest(QObject *parent) : QObject(parent)
{

}

void DepositTest::initTestCase()
{
    std::string names[100] = {"David","John","Paul","Mark","James","Andrew","Scott","Steven","Robert","Stephen","William","Craig","Michael","Stuart","Christopher","Alan","Colin","Brian","Kevin","Gary","Richard","Derek","Martin","Thomas","Neil","Barry","Ian","Jason","Iain","Gordon","Alexander","Graeme","Peter","Darren","Graham","George","Kenneth","Allan","Simon","Douglas","Keith","Lee","Anthony","Grant","Ross","Jonathan","Gavin","Nicholas","Joseph","Stewart","Daniel","Edward","Matthew","Donald","Fraser","Garry","Malcolm","Charles","Duncan","Alistair","Raymond","Philip","Ronald","Ewan","Ryan","Francis","Bruce","Patrick","Alastair","Bryan","Marc","Jamie","Hugh","Euan","Gerard","Sean","Wayne","Adam","Calum","Alasdair","Robin","Greig","Angus","Russell","Cameron","Roderick","Norman","Murray","Gareth","Dean","Eric","Adrian","Gregor","Samuel","Gerald","Henry","Justin","Benjamin","Shaun","Callum"};
    for (std::string name: names) {
        ShortcutEntry* entry = new ShortcutEntry();
        entry->Name = name;
        entry->RunCount = rand();
        deposit.Entries.push_back(entry);
    }

}

void DepositTest::cleanupTestCase()
{
    for (auto entry: deposit.Entries) {
        delete entry;
    }
}

void DepositTest::SearchAll()
{
    {
    auto result = deposit.SearchAll("David");

    QVERIFY(result->size() > 0);
    QCOMPARE(result->at(0), deposit.Entries[0]);
    }

    auto result = deposit.SearchAll("mar");
    std::vector<std::string> correctNames {"Mark", "Marc", "Martin"};
    QVERIFY(result->size() >= 3);

    QVERIFY(
        std::all_of(correctNames.begin(), correctNames.end(), [&](std::string name){
            return std::any_of(result->begin(), result->end(), [&](Entry* entry){
                return entry->Name == name;
            });
        })
    );
}

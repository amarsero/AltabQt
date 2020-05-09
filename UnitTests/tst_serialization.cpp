#include <QtTest>

#include <memory>
#include <sstream>

#include <shortcutentry.h>
#include <serializableobject.h>
#include <deserializableobject.h>

class Serialization : public QObject
{
    Q_OBJECT

public:
    Serialization();
    ~Serialization();
private:
    ShortcutEntry* newEntry = nullptr;
private slots:
    void initTestCase();
    void cleanupTestCase();
    void ShortcutEntrySerialization();

};

Serialization::Serialization()
{

}

Serialization::~Serialization()
{

}

void Serialization::initTestCase()
{

}

void Serialization::cleanupTestCase()
{
    if (newEntry != nullptr)
    {
        delete  newEntry;
        newEntry = nullptr;
    }
}

void Serialization::ShortcutEntrySerialization()
{
    std::unique_ptr<ShortcutEntry> entry = std::unique_ptr<ShortcutEntry>(new ShortcutEntry());

    entry->Name = "hola";
    entry->RunCount = 5;
    entry->FullPath = "some kind of path, you know";

    int length = entry->SerializedLength();
    char bytes[length];

    SerializableObject serializable(bytes, length, SerializableObjectTypeEnum::ShortcutEntry);

    entry->Serialize(serializable);

    auto vector = serializable.ToVector();

    int size;
    memcpy(&size, &vector[1], sizeof(int));

    DeserializableObject deserializable(&vector[0], size);

    newEntry = (ShortcutEntry*)Entry::Deserialize(deserializable);

    QCOMPARE(entry->RunCount, newEntry->RunCount);
    QCOMPARE(entry->Name, newEntry->Name);
    QCOMPARE(entry->FullPath, newEntry->FullPath);
    QCOMPARE(entry->TargetPath, newEntry->TargetPath);

    delete newEntry;
    newEntry = nullptr;
}

QTEST_APPLESS_MAIN(Serialization)

#include "tst_serialization.moc"

#include "serializationtest.h"

SerializationTest::SerializationTest()
{

}

void SerializationTest::initTestCase()
{

}

void SerializationTest::cleanupTestCase()
{
    if (newEntry != nullptr)
    {
        delete  newEntry;
        newEntry = nullptr;
    }
}

void SerializationTest::ShortcutEntrySerialization()
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

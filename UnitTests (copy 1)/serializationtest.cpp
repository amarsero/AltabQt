#include "serializationtest.h"

SerializationTest::SerializationTest()
{

}

void SerializationTest::initTestCase()
{

}

void SerializationTest::cleanupTestCase()
{
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

	DeserializableObject deserializable(&vector[0], size, vector[0]);

	auto result = Entry::Deserialize(deserializable);
	ShortcutEntry* newEntry = (ShortcutEntry*)result.get();

    QCOMPARE(entry->RunCount, newEntry->RunCount);
    QCOMPARE(entry->Name, newEntry->Name);
    QCOMPARE(entry->FullPath, newEntry->FullPath);
    QCOMPARE(entry->TargetPath, newEntry->TargetPath);
}

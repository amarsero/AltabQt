#include "shortcutentry.h"

#include <cstring>
#include <serializableobject.h>
#include <deserializableobject.h>

ShortcutEntry::ShortcutEntry()
= default;

bool ShortcutEntry::Run()
{
    RunCount++;
    try {
        if (!TargetPath.empty()) {
            system(TargetPath.c_str());
        } else {
            system(FullPath.c_str());
        }
        return true;
    } catch (const std::exception& e) {
        return false;
    }
}

bool ShortcutEntry::Matches(const std::string*  /*search*/) const {
    return false;
}

void ShortcutEntry::Serialize(SerializableObject& serialized) const
{
   int baseEntryLength = Entry::SerializedLength();
   char baseEntryBytes[baseEntryLength];

   SerializableObject baseEntry(baseEntryBytes, baseEntryLength, SerializableObjectTypeEnum::Entry);

   Entry::Serialize(baseEntry);
   serialized.Add(baseEntry);

   serialized.Add(FullPath);
   serialized.Add(TargetPath);
}

void ShortcutEntry::Deserialize(DeserializableObject& serialized, Entry* entry)
{
    ShortcutEntry* shortcutEntry = (ShortcutEntry*)entry;

    int size = serialized.GetDeserializableObjectBytesSize();
    char baseBytes[size];
    DeserializableObject baseDeserializable = serialized.GetDeserializableObject(baseBytes, size);
    Entry::FillDeserialize(baseDeserializable, entry);

    serialized.Get(shortcutEntry->FullPath);
    serialized.Get(shortcutEntry->TargetPath);
}

int ShortcutEntry::SerializedLength() const
{
    return Entry::SerializedLength() +
            sizeof(char) + //type of inner entry
            sizeof(int) + //type of inner entry
            sizeof(FullPath.size()) +
                FullPath.size() +
            sizeof(TargetPath.size()) +
                TargetPath.size();
}

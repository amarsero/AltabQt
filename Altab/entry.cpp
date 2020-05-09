#include "entry.h"
#include <shortcutentry.h>
#include <deserializableobject.h>
#include <cstring>

Entry::Entry()
{

}
Entry::~Entry() {

}

int Entry::SerializedLength() const {
    return sizeof(Name.size()) +
            Name.size() +
            sizeof(RunCount);
}

void Entry::Serialize(SerializableObject& serializing) const
{
    serializing.Add(Name);
    //Icon serialization missing
    serializing.Add(RunCount);
}

void Entry::FillDeserialize(DeserializableObject& serialized, Entry* entry)
{
    serialized.Get(entry->Name);
    //Icon deserialization missing
    serialized.Get(entry->RunCount);
}

class Entry* Entry::Deserialize(DeserializableObject& serialized)
{
    switch (serialized.Type) {
    case SerializableObjectType::Entry: {
        throw "This should never happen";
    }
    case SerializableObjectType::ShortcutEntry : {
        ShortcutEntry* entry = new ShortcutEntry();
        ShortcutEntry::Deserialize(serialized, entry);
        return entry;
    }
    default: {
        throw "This should never happen";
    }
    }

    return nullptr;
}


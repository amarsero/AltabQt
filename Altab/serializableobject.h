#ifndef SERIALIZABLEOBJECT_H
#define SERIALIZABLEOBJECT_H

#include <string>
#include <memory>
#include <vector>
#include <entry.h>

namespace SerializableObjectType {
    enum SerializableObjectTypeEnum: char {
        Entry,
        ShortcutEntry
    };
}

using SerializableObjectType::SerializableObjectTypeEnum;

class SerializableObject
{
public:
    SerializableObject(Entry& entry);

    const int length;
    const enum SerializableObjectTypeEnum Type;

    template<typename T>
    void Add(const T& item);

    std::vector<char> ToVector();

private:
    int index = 0;
    char bytes[];

};

#endif // SERIALIZABLEOBJECT_H

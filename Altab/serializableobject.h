#ifndef SERIALIZABLEOBJECT_H
#define SERIALIZABLEOBJECT_H

#include <string>
#include <memory>
#include <vector>

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
    SerializableObject(char* bytes, const int length, char type);

    const int length;
    const enum SerializableObjectTypeEnum Type;

    template<typename T>
    void Add(const T& item);

    std::vector<char> ToVector();

private:
    char* bytes;
    int index = 0;

};

#endif // SERIALIZABLEOBJECT_H

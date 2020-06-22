#ifndef DESERIALIZABLEOBJECT_H
#define DESERIALIZABLEOBJECT_H

#include <serializableobject.h>
#include <memory>

class DeserializableObject
{
public:
    DeserializableObject(char* bytes, const int length, const char type);

    const int length;
    const enum SerializableObjectTypeEnum Type;

    inline static DeserializableObject* StackAllocate();

    template<typename T>
    void Get(T& item);

    DeserializableObject GetDeserializableObject(char* bytes, const int size);
    int GetDeserializableObjectBytesSize();

private:
    char* bytes;
    int index = 0;
};

#endif // DESERIALIZABLEOBJECT_H

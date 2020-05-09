#include "deserializableobject.h"

#include <cstring>


DeserializableObject::DeserializableObject(char *bytes, const int length, const char type)
    : length(length), Type((SerializableObjectTypeEnum) type), bytes(bytes)
{
}

DeserializableObject::DeserializableObject(char *bytes, const int length)
    : length(length - sizeof (char) - sizeof (int)),
      Type((SerializableObjectTypeEnum)bytes[0]),
      bytes(bytes)
{
    index += sizeof (char) + sizeof (int);
}

inline DeserializableObject *DeserializableObject::StackAllocate()
{
    return (DeserializableObject*) alloca(sizeof(SerializableObject));
}

template<typename T>
void DeserializableObject::Get(T &item)
{
    memcpy(&item, &bytes[index], sizeof(item));
    index += sizeof(item);
}

template void DeserializableObject::Get<int>(int&);

template<>
void DeserializableObject::Get(std::string &string)
{
    size_t size;
    Get(size);

    string.assign(&bytes[index], size);
    index += size;
}

int DeserializableObject::GetDeserializableObjectBytesSize()
{
    int size = 0;
    memcpy(&size, &bytes[index+ sizeof(char)], sizeof(int));
    return size;
}

DeserializableObject DeserializableObject::GetDeserializableObject(char *baseBytes, const int size)
{
    char type;
    Get(type);

    index += sizeof(int); //padding, we already know the size

    memcpy(baseBytes, &bytes[index], size);
    index += size;

    return DeserializableObject(baseBytes, size, type);
}



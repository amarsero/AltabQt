#include "serializableobject.h"
#include <memory>
#include <cstring>



SerializableObject::SerializableObject(Entry& entry)
    : length(entry.SerializedLength()),
      bytes(32)
{

}


template<typename T>
void SerializableObject::Add(const T& item)
{
    memcpy(&bytes[index], &item, sizeof(item));
    index += sizeof(item);
}

template<>
void SerializableObject::Add(const std::string& string)
{
    auto stringSize = string.size();
    Add(stringSize);

    memcpy(&bytes[index], &string[0], stringSize);
    index += stringSize;
}

template<>
void SerializableObject::Add(const SerializableObject &serializable)
{
    Add(serializable.Type);
    Add(serializable.length);

    memcpy(&bytes[index], serializable.bytes, serializable.length);
    index += serializable.length;
}

std::vector<char> SerializableObject::ToVector()
{
    int totalSize = index + sizeof(char) + sizeof(int);
    std::vector<char> vector(totalSize);
    vector[0] = Type;
	memcpy(&vector[sizeof(char)], &index, sizeof(int));

    memcpy(&vector[sizeof(char) + sizeof(int)], bytes, index);

    return vector;
}



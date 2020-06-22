#ifndef ENTRY_H
#define ENTRY_H

#include <iostream>
#include <cstdint>
#include <serializableobject.h>
#include <deserializableobject.h>

class Entry
{
public:
    Entry();
    virtual ~Entry();
    std::string Name;
    u_int8_t* Icon{};
    mutable int RunCount{};
    virtual void Serialize(SerializableObject& serializing) const;
    static std::shared_ptr<Entry> Deserialize(DeserializableObject& serialized);

    virtual bool Run(){return false;}
    virtual bool Matches(const std::string* /*search*/) const{return false;}
    virtual int SerializedLength() const;

protected:
    static void FillDeserialize(DeserializableObject& serialized, Entry& entry);
};

#endif // ENTRY_H

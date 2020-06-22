#ifndef SHORTCUTENTRY_H
#define SHORTCUTENTRY_H

#include <entry.h>

class ShortcutEntry : public Entry
{
public:
    ShortcutEntry();
    std::string FullPath;
    std::string TargetPath;
    bool Run() override;
    bool Matches(const std::string *search) const override;
    void Serialize(SerializableObject& serialized) const override;
    int SerializedLength() const override;
	static void Deserialize(DeserializableObject& serialized, ShortcutEntry& entry) ;
};

#endif // SHORTCUTENTRY_H

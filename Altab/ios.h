#ifndef IOS_H
#define IOS_H

#include <filesystem>

class IOS
{
public:
    static IOS& Instance();
    virtual const std::filesystem::path& GetSaveFolder() = 0;
};

#endif // IOS_H


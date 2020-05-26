#ifndef IOS_H
#define IOS_H

#include <string>
#include <map>

class IOS
{
public:
    static IOS& Instance();
    virtual std::string GetSaveFolder() = 0;
protected:
    std::map<std::string, std::string> cache{};
private:
    static IOS* instance;
};

#endif // IOS_H


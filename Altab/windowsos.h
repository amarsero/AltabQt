#ifndef WINDOWSOS_H
#define WINDOWSOS_H
#include <ios.h>

class WindowsOS : public IOS
{
public:
    WindowsOS();

    const std::filesystem::path& GetSaveFolder() override;
};

#endif // WINDOWSOS_H

#ifndef LINUXOS_H
#define LINUXOS_H
#include <ios.h>

class LinuxOS : public IOS
{
public:
    LinuxOS();

    const std::filesystem::path& GetSaveFolder() override;
};

#endif // LINUXOS_H

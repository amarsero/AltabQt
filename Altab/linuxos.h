#ifndef LINUXOS_H
#define LINUXOS_H
#include <ios.h>

class LinuxOS : public IOS
{
public:
    LinuxOS();

    std::string GetSaveFolder() override;
};

#endif // LINUXOS_H

#include "linuxos.h"

LinuxOS::LinuxOS()
{

}

std::string LinuxOS::GetSaveFolder()
{
    return std::string("~/.config/altab/");
}

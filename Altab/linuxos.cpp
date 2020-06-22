#include "linuxos.h"
#include <stdlib.h>

LinuxOS::LinuxOS()
{

}

const std::filesystem::path& LinuxOS::GetSaveFolder()
{
    static const std::filesystem::path saveFolder{
        std::string{getenv("HOME")} +
        "/.config/altab/"};
    return saveFolder;
}

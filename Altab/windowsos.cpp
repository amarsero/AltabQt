#include "windowsos.h"
#include <stdlib.h>

WindowsOS::WindowsOS()
{

}

const std::filesystem::path& WindowsOS::GetSaveFolder()
{
    static const std::filesystem::path saveFolder{
        std::string{getenv("HOME")} +
        std::filesystem::path::preferred_separator +
        "altab" +
        std::filesystem::path::preferred_separator};

    return saveFolder;
}
